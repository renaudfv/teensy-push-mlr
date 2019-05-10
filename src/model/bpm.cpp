#include "model/bpm.h"

Bpm::Bpm(const int bpm) {
  beatsPerMinute_ = bpm;
}

Bpm::~Bpm() {}

int Bpm::getBeatsPerMinute() {
  return beatsPerMinute_;
}

int Bpm::getBeatLenghtMs() {
  return 60.0 / beatsPerMinute_ * 1000;
}

void Bpm::setBeatsPerMinute(const int bpm) {
  beatsPerMinute_ = bpm;
  notify();
}
