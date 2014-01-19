#include "starburst.h"

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0)); // seed randomness (iff A0 is unconnected, change if not)
  writebyte(7, 4);
}

void loop() {
  Serial.println(readbyte(4));
  digitalWrite(13, HIGH);
}
