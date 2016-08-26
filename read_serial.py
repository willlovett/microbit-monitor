#!/usr/bin/env python

import time
import serial
import os
from fnmatch import fnmatch
from subprocess import call

# Known monitors
# To add a monitor here, plug the microbit into your monitor USB then:
# - ls /dev/cu.usb* gives you the serial device
# - fb-rotate -l shows your displays.  Choose the right one and insert its
#   display ID here
monitors = {
  'cu.usbmodem232': '0x28da57c1',
  'cu.usbmodem242': '0x28da57c1'
}
monitor_id = None

class Microbit:

  def __init__(self, device):
    if device not in monitors:
      print "Unknown usb device '{}'".format(device)
      print "Please add it to the monitors dictionary"
      exit(1)
    self.monitor_id = monitors[device]
    self.device = device
    self.ser = serial.Serial(
      port=os.path.join('/dev', device),
      baudrate=115200
      # ,
      # parity=serial.PARITY_ODD,
      # stopbits=serial.STOPBITS_TWO,
      # bytesize=serial.SEVENBITS
    )
    self.ser.isOpen()
    print "Monitoring /dev/"+device
  def monitor(self):
    try:
      while True:
        time.sleep(0.1)
        out = ''
        while self.ser.inWaiting() > 0:
          out += self.ser.read(1)

        self.action(out)
    except IOError:
      return
  def lookupMethod(self, command):
    return getattr(self, 'do_' + command.upper(), None)
  def action(self, line):
    line = line.strip()
    parts = line.split(None, 1)
    if parts:
        method = self.lookupMethod(parts[0])
        if not method:
          return self.do_UNKNOWN(parts[0])
        if len(parts) == 2:
            return method(parts[1])
        else:
            return method('')
  def do_UNKNOWN(self, command):
    print "UNKNOWN COMMAND: " + command
  def do_MICROBIT_ACCELEROMETER_EVT_TILT_RIGHT(self, rest):
    print "Right"
    call(['fb-rotate', '-d', self.monitor_id, '-r', '90'])
  def do_MICROBIT_ACCELEROMETER_EVT_TILT_UP(self, rest):
    print "Up"
    call(['fb-rotate', '-d', self.monitor_id, '-r', '0'])
  def do_MICROBIT_ACCELEROMETER_EVT_TILT_LEFT(self, rest):
    print "Left"
    call(['fb-rotate', '-d', self.monitor_id, '-r', '270'])
  def do_MICROBIT_ACCELEROMETER_EVT_TILT_DOWN(self, rest):
    print "Down"
    call(['fb-rotate', '-d', self.monitor_id, '-r', '180'])


while(True):
  serial_ports = [file for file in os.listdir('/dev')
                  if fnmatch(file, "cu.usbmodem*")]
  
  if not serial_ports:
    print "I couldn't find any microbits plugged in via usb"
  elif len(serial_ports) > 1:
    print "I found multiple microbits plugged in, so can't tell which one to use"
    for sp in serial_ports:
      print sp
  else:
    device = serial_ports[0]
    Microbit(device).monitor()
  time.sleep(1)