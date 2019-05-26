#include "teensy3/Arduino.h"
#include "sense/serial-view.h"
#include "model/sequence.h"

SerialView::SerialView(
  Sequence* s1,
  Sequence* s2,
  Sequence* s3,
  Sequence* s4): s1_(s1), s2_(s2), s3_(s3), s4_(s4) {
    s1_->subscribe(this);
    s2_->subscribe(this);
    s3_->subscribe(this);
    s4_->subscribe(this);
}

SerialView::~SerialView() {}

void SerialView::update() {
  Serial.printf("%d %d %d %d\n\n", s1_->getCurrent(), s2_->getCurrent(), s3_->getCurrent(), s4_->getCurrent());
}
