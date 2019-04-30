#include "teensy3/Arduino.h"
#include "sequencer-controller.h"
#include "bpm.h"

SequencerController::SequencerController(Bpm* b): bpm_(b) {}

void SequencerController::start() {
  int tb = bpm_->GetBeatsPerMinute();
  Serial.printf("%d %d\n",tb, 0);
}
