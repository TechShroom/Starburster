#include "starburst.h"

int pin = 13, addr = 3;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0)); // seed randomness (iff A0 is unconnected, change if not)
  pinMode(pin, OUTPUT);
  writebyte(32, addr);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    Serial.println(String(readbit(addr, i) == 1) + "<-" + String(i));
    digitalWrite(pin, (readbit(addr, i) == 1) ? HIGH : LOW);
    delay(1000);
    digitalWrite(pin, LOW);
    delay(1000);
  }
}
