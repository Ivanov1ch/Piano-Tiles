#include <Wire.h>

const int LEDPins[4][4] = {{13, 12, 11, 10}, {9, 8, 7, 6}, {5, 4, 3, 2}, {A0, A1, A2, A3}};
const int numRows = sizeof(LEDPins)/sizeof(LEDPins[0]);
const int numCols = sizeof(LEDPins[0])/sizeof(LEDPins[0][0]);

const int BuzzerPin = 11;

const int numSongs = 2;

int rowProgression[13] = {3, 2, 2, 1, 0, -1, -1, 2, -1, 3, 2, 1, 0};
int currentlyLitLEDs[numRows][2] = {};
int rowsShown = 0, rowsCleared = 0, numRests = 0, progressionLen = sizeof(rowProgression) / sizeof(rowProgression[0]);
bool isFirstNote = true;

void setup() {
  Wire.begin(); //since no address specified, joins as Master
  Serial.begin(9600);
  
  // Initialize LEDs and Piezo as outputs
  pinMode(BuzzerPin, OUTPUT);
  for (int i = 0; i < numRows; i++)
    for (int j = 0; j < numCols; j++)
      pinMode(LEDPins[i][j], OUTPUT);

  Serial.print("Starting Shit");
}

void loop() {

  //Serial.println("Asking for which song to play");
  
  // Init array of 0s (all unpressed)
  int buttonStatuses[] = {0,0,0,0};

  Wire.requestFrom(1, numSongs); // request which button has been pressed
  byte numInputs = Wire.available();
  if(numInputs > 0) Serial.print("Slave responded!");
  for (int i=0; i<numInputs; ++i) {
    int statusButtonI = Wire.read();
    buttonStatuses[i] = statusButtonI;
  }

  if(buttonStatuses[0] == HIGH) playSong1();
  if(buttonStatuses[1] == HIGH) playSong2();
  


}
/*
void updateButtons() {
  Wire.requestFrom(1, numSongs); // request which button has been pressed
  byte numInputs = Wire.available();
  for (int i=0; i<numInputs; ++i) {
    int statusButtonI = Wire.read();
    buttonStatuses[i] = statusButtonI;
  }
}
*/



void playSong1() {
  Serial.println("Song 1");
  delay(1000);
  
}

void playSong2() {
  Serial.println("Song 2");
  delay(1000);
  
}
