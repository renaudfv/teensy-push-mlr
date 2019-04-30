#include "teensy3/Arduino.h"
#include "bpm.h"
#include "sequence.h"
#include "sequencer.h"
#include "sequencer-controller.h"
#include "serial-view.h"

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
  Sequencer* stepSequencer = new Sequencer(b, seq1, seq2, seq3, seq4);

  /**** CONTROLLERS ****/
  SequencerController* seqController = new SequencerController(stepSequencer);

  /**** VIEWS ****/
  SerialView* view = new SerialView(seq1, seq2, seq3, seq4);

  /**** EXECUTION ****/
  seqController->start();
}
