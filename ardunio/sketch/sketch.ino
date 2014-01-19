#include "starburst.h"

int pin = 13, addr = 3;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0)); // seed randomness (iff A0 is unconnected, change if not)
  pinMode(pin, OUTPUT);
  writebyte(random(127), addr);
  Serial.println(avaliablebytestacks());
}

void loop() {
  writebyte(random(127), addr);
  String build = "";
  build += String(readbyte(addr)) + "=";
  for (int i = 0; i < 8; i++) {
    build += String(readbit(addr, i) << i);
    if(i != 7) {
      build +="+";
    }
  }
  Serial.println(build);
  delay(1500);
}

