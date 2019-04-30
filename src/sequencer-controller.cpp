#include "bpm.h"
#include "sequencer.h"
#include "sequencer-controller.h"

SequencerController::SequencerController(Sequencer* seq): sequencer_(seq) {}

SequencerController::~SequencerController() {
  delete sequencer_;
}

void SequencerController::start() {
  while(1) {
    sequencer_->step();
  }
}
