#include <Arduino.h>

#include "bpm.h"
#include "sequencer-controller.h"

int main() {
  // Wait for serial to be available
  while(!Serial);

  // Baud rate may be changed
  Serial.begin(9600);
  Serial.printf("Started \n");

  Bpm* b = new Bpm(60);
  SequencerController* seqController = new SequencerController(b);

  seqController->start();
}
