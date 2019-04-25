#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <Arduino.h>


#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))

void start() {
  while(1) {
    GPIOC_PSOR = 1<<5; // PSOR only sets the concerned bit
		_delay_ms(2000);
    GPIOC_PCOR = 1<<5;
		_delay_ms(1000);
    Serial.printf("%s\n", "1 2 test");
  }
}

int main() {
  pinMode(13, OUTPUT);
  start();
}
