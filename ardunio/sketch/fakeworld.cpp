#include <Arduino.h>
#include "fakeworld.h"

const int size_ = 4;

// ref'd by first 2 bits for addr1 (0, 1, 10, 11)
// and last 3 for addr 2 (0,1,10,11,100,101,110,111)
byte fakebits[size_];

byte readfake(int addr, int addr2) {
  int index = addr, index2 = addr2;
  byte val = fakebits[index];
  return (val >> index2) & 1;
}

void writefake(byte bit_, int addr, int addr2) {
  int index = addr, index2 = addr2;
  byte pre = fakebits[index];
  fakebits[index] = (bit_ == 1) ? pre | (1 << index2) : pre & ~(1 << index2);
}

int size0() {
  return size_;
}
