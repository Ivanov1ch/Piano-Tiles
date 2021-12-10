#include <Wire.h>
#include <LiquidCrystal.h>

// Order: same as columns, from left to right (green, blue, yellow, white)
const int buttonPins[4] = {7, 4, 6, 5};
const int numButtons = sizeof(buttonPins)/sizeof(buttonPins[0]);

void setup() {
  Wire.begin(1);
  
  Wire.onReceieve(sendButtons);
  for(int i = 0; i < numButtons; i++)
    pinMode(buttonPins[i], INPUT);
}

void sendButtons(int numbytes) {
  
  Wire.beginTransmission(0);
  for(int buttonPin:buttonPins) {
    Wire.write(HIGH - digitalRead(buttonPin));
  }
  Wire.endTransmission();
}

void startScreen(int numbytes) {
  // Code that greets user and updates user on which was pressed


  Wire.beginTransmission(0);
  for(int buttonPin:buttonPins) {
    Wire.write(HIGH - digitalRead(buttonPin));
  }
  Wire.endTransmission();
}

void loop() {
  delay(10);
}
