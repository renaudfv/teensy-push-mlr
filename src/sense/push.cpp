#include "teensy3/Arduino.h"

#include "sense/push.h"

// uint8_t[] getPadRGB(int index) {
//   return { 240, 71, 127, 21, 4, 0, 8, index, 0, 255, 255, 255, 255, 255, 255, 247};
// }

Push::Push(Sequence* s1,
Sequence* s2,
Sequence* s3,
Sequence* s4): s1_(s1), s2_(s2), s3_(s3), s4_(s4) {
  s1_->subscribe(this);
  s2_->subscribe(this);
  s3_->subscribe(this);
  s4_->subscribe(this);
}

Push::~Push() {
  delete s1_;
  delete s2_;
  delete s3_;
  delete s4_;
}

void Push::init() {
  // Set Live mode
  uint8_t data[9] = {240, 71, 127, 21, 98, 0, 1, 0, 247};
  // Index 7 is the pad number [0-63]
  uint8_t white[16] = {240, 71, 127, 21, 4, 0, 8, 9, 0, 2, 22, 2, 22, 2, 22, 247};
  uint8_t black[16] = {240, 71, 127, 21, 4, 0, 8, 9, 0, 0, 0, 0, 0, 0, 0, 247};


  usbMIDI.sendSysEx(9, data);

  for(int i = 0; i < 64; i++) {
    white[7] = i;
    black[7] = i;

    usbMIDI.sendSysEx(16, white);
    delay(66);
    usbMIDI.sendSysEx(16, black);
    delay(10);
  }
}

void Push::_sequenceOn(uint8_t i1, uint8_t i2, uint8_t i3, uint8_t i4) {
  uint8_t white1[16] = {240, 71, 127, 21, 4, 0, 8, i1, 0, 2, 22, 2, 22, 2, 22, 247};
  uint8_t white2[16] = {240, 71, 127, 21, 4, 0, 8, (i2 + 16), 0, 2, 22, 2, 22, 2, 22, 247};
  uint8_t white3[16] = {240, 71, 127, 21, 4, 0, 8, (i3 + 32), 0, 2, 22, 2, 22, 2, 22, 247};
  uint8_t white4[16] = {240, 71, 127, 21, 4, 0, 8, (i4 + 48), 0, 2, 22, 2, 22, 2, 22, 247};

  usbMIDI.sendSysEx(16, white1);
  usbMIDI.sendSysEx(16, white2);
  usbMIDI.sendSysEx(16, white3);
  usbMIDI.sendSysEx(16, white4);
}

void Push::_sequenceOff(uint8_t i1, uint8_t i2, uint8_t i3, uint8_t i4) {
  uint8_t black1[16] = {240, 71, 127, 21, 4, 0, 8, i1, 0, 0, 0, 0, 0, 0, 0, 247};
  uint8_t black2[16] = {240, 71, 127, 21, 4, 0, 8, (i2 + 16), 0, 0, 0, 0, 0, 0, 0, 247};
  uint8_t black3[16] = {240, 71, 127, 21, 4, 0, 8, (i3 + 32), 0, 0, 0, 0, 0, 0, 0, 247};
  uint8_t black4[16] = {240, 71, 127, 21, 4, 0, 8, (i4 + 48), 0, 0, 0, 0, 0, 0, 0, 247};

  usbMIDI.sendSysEx(16, black1);
  usbMIDI.sendSysEx(16, black2);
  usbMIDI.sendSysEx(16, black3);
  usbMIDI.sendSysEx(16, black4);
}

void Push::update() {
  this->_sequenceOff(
    s1_->getCurrent() - 1,
    s2_->getCurrent() - 1,
    s3_->getCurrent() - 1,
    s4_->getCurrent() - 1
  );
 this->_sequenceOn(
   s1_->getCurrent(),
   s2_->getCurrent(),
   s3_->getCurrent(),
   s4_->getCurrent()
 );
}
