#include <Arduino.h>
#include "starburst.h"
#include "fakeworld.h"

byte readbyte(int addr) {
  byte b = 0;
  for (int i = 0; i < 8; i++) {
    Serial.println(i);
    b |= (readbit(addr | i) << i);
  }
  return b;
}

void writebyte(byte b, int addr) {
  for (int i = 0; i < 8; i++) {
    writebit(b & bit(i), (addr | i));
  }
}

/* Byte is smallest number, booleans are actually bytes */
byte readbit(int addr) {
  return readfake(addr); // placeholder
}

void writebit(byte b, int addr) {
  writefake(b, addr);
}
