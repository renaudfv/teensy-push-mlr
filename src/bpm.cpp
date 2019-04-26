#include "bpm.h"

Bpm::Bpm(const int bpm) {
  this->beatsPerMinute = bpm;
}

int Bpm::GetBeatsPerMinute() {
  return this->beatsPerMinute;
}

int Bpm::GetBeatLenghtMs() {
  return 60.0 / this->beatsPerMinute * 1000;
}

void Bpm::SetBeatsPerMinute(const int bpm) {
  this->beatsPerMinute = bpm;
}
