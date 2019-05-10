#include "teensy3/Arduino.h"

#include "sense/push.h"

Push::Push() {
}

Push::~Push() {
}

void Push::init() {
  Serial.print("HERE FIRST");
  uint8_t data[9] = {240, 71, 127, 21, 98, 0, 1, 1, 247};
  Serial.print("THEYT ");
  while(1) {
    usbMIDI.sendSysEx(9, data);
    delay(500);
  }
}
