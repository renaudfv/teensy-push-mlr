#include "teensy3/Arduino.h"

#include "sense/push.h"

// uint8_t[] getPadRGB(int index) {
//   return { 240, 71, 127, 21, 4, 0, 8, index, 0, 255, 255, 255, 255, 255, 255, 247};
// }

Push::Push() {
}

Push::~Push() {
}

void Push::init() {
  // Set Live mode
  uint8_t data[9] = {240, 71, 127, 21, 98, 0, 1, 0, 247};


  usbMIDI.sendSysEx(9, data);

  // Index 7 is the pad number [0-71]
  uint8_t white[16] = {240, 71, 127, 21, 4, 0, 8, 0, 0, 2, 22, 2, 22, 2, 22, 247};
  uint8_t black[16] = {240, 71, 127, 21, 4, 0, 8, 9, 0, 0, 0, 0, 0, 0, 0, 247};

  for(int i = 0; i < 64; i++) {
    white[7] = i;
    black[7] = i;

    usbMIDI.sendSysEx(16, white);
    delay(33);
    usbMIDI.sendSysEx(16, black);
    delay(10);
  }
}
