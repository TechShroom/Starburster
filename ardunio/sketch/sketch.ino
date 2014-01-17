void setup() {
  
}

void loop() {
  
}

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
byte readbit() {
  return 0; // placeholder
}

void writebit(byte b) {
  
}
