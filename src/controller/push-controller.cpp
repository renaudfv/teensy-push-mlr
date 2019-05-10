#include "teensy3/Arduino.h"

#include "sense/push.h"
#include "sense/sequencer.h"
#include "controller/push-controller.h"

PushController::PushController(Push* push): push_(push) {}

PushController::~PushController() {
  delete push_;
}

void PushController::start() {
  push_->init();
}
