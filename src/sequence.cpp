#include "sequence.h"

Sequence::Sequence(int start, int end):
  start_(start),
  end_(end),
  current_(start)
{}

Sequence::~Sequence() {}

void Sequence::nextStep() {
  // Notify first since the updated value will be used on the next step
  notify();

  if(current_ < end_)
  {
    current_++;
  }
  else {
    current_ = start_;
  }
}

void Sequence::setStart(int start) {
  start_ = start;

  notify();
}

void Sequence::setEnd(int end) {
  end_ = end;

  notify();
}

int Sequence::getCurrent() {
  return current_;
}
