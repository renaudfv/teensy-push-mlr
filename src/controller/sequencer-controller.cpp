#include "model/bpm.h"
#include "sense/sequencer.h"
#include "controller/sequencer-controller.h"

SequencerController::SequencerController(Sequencer* seq): sequencer_(seq) {}

SequencerController::~SequencerController() {
  delete sequencer_;
}

void SequencerController::start() {
  while(1) {
    sequencer_->step();
  }
}
