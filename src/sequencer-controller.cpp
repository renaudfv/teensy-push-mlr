#include "sequencer-controller.h"

SequencerController::SequencerController(const Bpm& b) {
  this->beatsPerMinute = &b;
}

void SequencerController::start() {
  int tb = this->beatsPerMinute.GetBeatsPerMinute();
  Serial.printf("%d %d\n",tb, 0);
}
