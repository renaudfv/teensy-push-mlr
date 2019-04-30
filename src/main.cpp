#include "teensy3/Arduino.h"
#include "bpm.h"
#include "sequencer-controller.h"

// Created and binds the MIDI interface to the default hardware Serial port

int main() {
  // Wait for serial to be available
  while (!Serial);
  usbMIDI.begin();
  Serial.begin(115200);

  uint8_t data[10] = {0xF0, 0x41, 0x36, 0x00, 0x23, 0x20, 0x01, 0x00, 0x01, 0xF7 };


  // Baud rate may be changed
  Bpm* b = new Bpm(60);
  SequencerController* seqController = new SequencerController(b);

  seqController->start();

  while(1) {
    Serial.print("Start\n");
    usbMIDI.sendSysEx(10, data);
    delay(500);
  }
}
