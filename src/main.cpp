#include <avr/io.h>
#include <Arduino.h>

void start() {
  while(1) {
    GPIOC_PSOR = 1<<5; // PSOR only sets the concerned bit
		delay(2000);
    GPIOC_PCOR = 1<<5;
		delay(1000);
  }
}

int main() {
  pinMode(13, OUTPUT);
  start();
}
