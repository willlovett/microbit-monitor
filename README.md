# microbit-monitor

Some code to do cool stuff with a microbit when attached to a monitor.

Currently this does one thing - it knows which orientation the monitor is in,
and sends that event over USB serial.  The included python, when run on a Mac,
receives this event and orients the display on that monitor appropriately

#Setup
1. Install yotta: https://lancaster-university.github.io/microbit-docs/offline-toolchains/#yotta
2. Clone and build fb-rotate, ensuring it's in your path: https://github.com/CdLbB/fb-rotate
3. Plug your microbit into a usb device on your monitor (and ensure it's eventually hooked up to your mac)
4. Build and install:
   ```
   yt build
   cp build/bbc-microbit-classic-gcc/source/microbit-monitor-combined.hex /Volumes/MICROBIT/
   ```
5. Add your usb device -> monitor ID map
   * Run ```fb-rotate -l```.  The output shows a number of Display IDs, and their resolution.  Make note of the display ID to which your microbit is attached
   * Run ```ls /dev/cu.usbmodem*```.  Make note of the cu.usbmodem<number> device name
   * Modify read_serial.py, adding an entry to the 'monitors' dictionary, mapping from usb device name (eg. 'cu.usbmodem232') to fb-rotate device ID (eg '0x28da57c1')
5. Run the python daemon
   ```
   ./read_serial.py
   ```
6. Rotate your monitor
7. Gasp in amazement as your display configuration rotates automagically