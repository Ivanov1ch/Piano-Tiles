#include <Wire.h>
// This is the MASTER arduino in the I2C communication chain

void setup() {
  Wire.begin();
}

void loop() {
  Wire.beginTransmission(1);
  Wire.write(1);             
  Wire.endTransmission();
}
