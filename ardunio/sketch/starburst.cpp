#include <Arduino.h>
#include "starburst.h"
#include "fakeworld.h"

byte readbyte() {
  byte b = 0;
  for (int i = 0; i < 8; i++) {
    b |= (readbit() << i);
  }
  return b;
}

void writebyte(byte b) {
  for (int i = 0; i < 8; i++) {
    writebit(b & bit(i));
  }
}

/* Byte is smallest number, booleans are actually bytes */
byte readbit(int addr) {
  return readfake(addr); // placeholder
}

void writebit(byte b, int addr) {
  writefake(b, addr);
}
