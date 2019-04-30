#include "teensy3/Arduino.h"

#include "bpm.h"
#include "sequence.h"
#include "sequencer.h"

Sequencer::Sequencer(
  Bpm* b,
  Sequence* s1,
  Sequence* s2,
  Sequence* s3,
  Sequence* s4
): bpm_(b), seq1_(s1), seq2_(s2), seq3_(s3), seq4_(s4) {}

Sequencer::~Sequencer() {
  delete bpm_;
  delete seq1_;
  delete seq2_;
  delete seq3_;
  delete seq4_;
}

// Each step should last a bpm MS lenght
void Sequencer::step() {
  seq1_->nextStep();
  seq2_->nextStep();
  seq3_->nextStep();
  seq4_->nextStep();

  delay(bpm_->getBeatLenghtMs());
}
