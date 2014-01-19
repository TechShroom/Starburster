#include <Arduino.h>
#include "starburst.h"
#include "fakeworld.h"

byte readbyte(int addr) {
  byte b = 0;
  for (int i = 0; i < 8; i++) {
    b |= (readbit(addr, i) << i);
  }
  return b;
}

void writebyte(byte b, int addr) {
  for (int i = 0; i < 8; i++) {
    writebit((b & bit(i)) >> i, addr, i);
  }
}

/* Byte is smallest number, booleans are actually bytes */
byte readbit(int addr, int addr2) {
  return readfake(addr, addr2); // placeholder
}

void writebit(byte b, int addr, int addr2) {
  writefake(b, addr, addr2);
}
