#include "teensy3/Arduino.h"
#include "model/bpm.h"
#include "model/sequence.h"
#include "sense/sequencer.h"
#include "sense/push.h"
#include "sense/serial-view.h"
#include "controller/sequencer-controller.h"
#include "controller/push-controller.h"

int main() {
  /**** SETUP ****/
  while (!Serial);
  Serial.begin(115200);

  /**** MODELS ****/
  Bpm* b = new Bpm(80);
  Sequence* seq1 = new Sequence(1, 16);
  Sequence* seq2 = new Sequence(1, 16);
  Sequence* seq3 = new Sequence(1, 16);
  Sequence* seq4 = new Sequence(1, 16);

  /**** SENSES ****/
  Sequencer* stepSequencer = new Sequencer(b, seq1, seq2, seq3, seq4);
  Push* push = new Push(seq1, seq2, seq3, seq4);
  SerialView* view = new SerialView(seq1, seq2, seq3, seq4);

  /**** CONTROLLERS ****/
  // Controllers could initiate senses and models internally
  SequencerController* seqController = new SequencerController(stepSequencer);
  PushController* pushController = new PushController(push);

  /**** EXECUTION ****/
  pushController->start();
  // Started at the end since the main running loop is in there
  seqController->start();
}
