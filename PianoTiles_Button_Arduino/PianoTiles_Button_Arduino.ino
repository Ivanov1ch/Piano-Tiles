#include <Wire.h>

// Order: same as columns, from left to right (green, blue, yellow, white)
const int buttonPins[4] = {7, 4, 6, 5};
const int numButtons = sizeof(buttonPins)/sizeof(buttonPins[0]);

void setup() {
  Wire.begin();

  for(int i = 0; i < numButtons; i++)
    pinMode(buttonPins[i], INPUT);
}

void loop() {
  Wire.beginTransmission(0x2);
  for(int i = 0; i < numButtons; i++)
    Wire.write(HIGH - digitalRead(buttonPins[i]));
  Wire.endTransmission();
  delay(10);
}
