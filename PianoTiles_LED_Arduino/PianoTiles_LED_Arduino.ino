#include <Wire.h>

const int pinsYellow[] = {13, 12, 11, 10};
const int pinsBlue[] = {9, 8, 7, 6};
const int pinsGreen[] = {5, 4, 3, 2};
const int pinsWhite[] = {A0, A1, A2, A3};

void setup() {
  Wire.begin(1);  
  Wire.onReceive(receiveEvent);

  for (int i = 0; i < 4; i++) {
    pinMode(pinsBlue[i], OUTPUT);
    pinMode(pinsGreen[i], OUTPUT);
    pinMode(pinsYellow[i], OUTPUT);
    pinMode(pinsWhite[i], OUTPUT);
  }
}

int lastReceivedMessage = -1;

void receiveEvent(int numBytes) {
  lastReceivedMessage = Wire.read();
}

void loop() {
  if(lastReceivedMessage == 1) {
    digitalWrite(pinsBlue[0], HIGH);
  }
}
