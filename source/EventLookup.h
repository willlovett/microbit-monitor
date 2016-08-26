// Converts Microbit events to strings

#include "Microbit.h"

ManagedString lookupGesture(int e, bool brief = false) {
  switch(e) {
  default: return brief ? "?" : "UNKNOWN_GESTURE";
  case MICROBIT_ACCELEROMETER_EVT_NONE:
    return brief ? "NONE" : "MICROBIT_ACCELEROMETER_EVT_NONE";
  case MICROBIT_ACCELEROMETER_EVT_TILT_UP:
    return brief ? "UP" : "MICROBIT_ACCELEROMETER_EVT_TILT_UP";
  case MICROBIT_ACCELEROMETER_EVT_TILT_DOWN:
    return brief ? "DOWN" : "MICROBIT_ACCELEROMETER_EVT_TILT_DOWN";
  case MICROBIT_ACCELEROMETER_EVT_TILT_LEFT:
    return brief ? "LEFT" : "MICROBIT_ACCELEROMETER_EVT_TILT_LEFT";
  case MICROBIT_ACCELEROMETER_EVT_TILT_RIGHT:
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

ManagedString lookup(int type, int e, bool brief = false) {
  switch(type) {
  case MICROBIT_ID_GESTURE:
    return lookupGesture(e, brief);
  default:
    return "UNKNOWN_TYPE";
  }
}
