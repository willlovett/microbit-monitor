/*
TODO - add licensing

Copyright (c) 2016 Will Lovett
*/

#include "MicroBit.h"
#include "MicroBitUARTService.h"

#include "EventLookup.h"

MicroBit uBit;
MicroBitUARTService *uart;
MicroBitSerial *serial;

void onGesture(MicroBitEvent e) {
  ManagedString Event = lookupGesture(uBit, e.value);
  ManagedString ShortEvent = lookupGesture(uBit, e.value, true);
  if (e.value != MICROBIT_ACCELEROMETER_EVT_NONE) {
    uBit.display.printAsync(ShortEvent);
    serial->send(Event);
  }
}

int main()
{
    // Initialise the micro:bit runtime.
  uBit.init();

  uart = new MicroBitUARTService(*uBit.ble, 32, 32);
  serial = new MicroBitSerial(USBTX, USBRX);
  uBit.messageBus.listen(MICROBIT_ID_GESTURE, MICROBIT_EVT_ANY, onGesture);

  while(1)
  {
    uBit.sleep(100);
  }

  // If main exits, there may still be other fibers running or registered Event handlers etc.
  // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
  // sit in the idle task forever, in a power efficient sleep.
  release_fiber();
}

