// Converts Microbit events to strings

#include "Microbit.h"

ManagedString lookupGesture(MicroBit &uBit, int e, bool brief = false) {
  switch(e) {
  default: return brief ? "?" : "UNKNOWN_GESTURE";
  case MICROBIT_ACCELEROMETER_EVT_NONE:
    return brief ? "NONE" : "MICROBIT_ACCELEROMETER_EVT_NONE";
  case MICROBIT_ACCELEROMETER_EVT_TILT_UP:
    uBit.display.rotateTo(MICROBIT_DISPLAY_ROTATION_0);
    return brief ? "UP" : "MICROBIT_ACCELEROMETER_EVT_TILT_UP";
  case MICROBIT_ACCELEROMETER_EVT_TILT_DOWN:
    uBit.display.rotateTo(MICROBIT_DISPLAY_ROTATION_180);
    return brief ? "DOWN" : "MICROBIT_ACCELEROMETER_EVT_TILT_DOWN";
  case MICROBIT_ACCELEROMETER_EVT_TILT_LEFT:
    uBit.display.rotateTo(MICROBIT_DISPLAY_ROTATION_270);
    return brief ? "LEFT" : "MICROBIT_ACCELEROMETER_EVT_TILT_LEFT";
  case MICROBIT_ACCELEROMETER_EVT_TILT_RIGHT:
    uBit.display.rotateTo(MICROBIT_DISPLAY_ROTATION_90);
    return brief ? "RIGHT" : "MICROBIT_ACCELEROMETER_EVT_TILT_RIGHT";
  case MICROBIT_ACCELEROMETER_EVT_FACE_UP:
    return brief ? "FACE_UP" : "MICROBIT_ACCELEROMETER_EVT_FACE_UP";
  case MICROBIT_ACCELEROMETER_EVT_FACE_DOWN:
    return brief ? "FACE_DOWN" : "MICROBIT_ACCELEROMETER_EVT_FACE_DOWN";
  case MICROBIT_ACCELEROMETER_EVT_FREEFALL:
    return brief ? "FREEFALL" : "MICROBIT_ACCELEROMETER_EVT_FREEFALL";
  case MICROBIT_ACCELEROMETER_EVT_3G:
    return brief ? "3G" : "MICROBIT_ACCELEROMETER_EVT_3G";
  case MICROBIT_ACCELEROMETER_EVT_6G:
    return brief ? "6G" : "MICROBIT_ACCELEROMETER_EVT_6G";
  case MICROBIT_ACCELEROMETER_EVT_8G:
    return brief ? "8G" : "MICROBIT_ACCELEROMETER_EVT_8G";
  case MICROBIT_ACCELEROMETER_EVT_SHAKE:
    return brief ? "SHAKE" : "MICROBIT_ACCELEROMETER_EVT_SHAKE";
  }
}

ManagedString lookup(MicroBit &uBit, int type, int e, bool brief = false) {
  switch(type) {
  case MICROBIT_ID_GESTURE:
    return lookupGesture(uBit, e, brief);
  default:
    return "UNKNOWN_TYPE";
  }
}
