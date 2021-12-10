#include <Wire.h>

const int BuzzerPin = 12;
const int LEDPins[4][4] = {{A3, A2, A1, A0}, {12, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 13}};
const int numRows = sizeof(LEDPins)/sizeof(LEDPins[0]);
const int numCols = sizeof(LEDPins[0])/sizeof(LEDPins[0][0]);

const int numSongs = 2;

int currentlyLitLEDs[numRows][2] = {};
int rowsShown = 0, rowsCleared = 0, numRests = 0;
bool isFirstNote = true;

int gameState, chosenSong, chosenSongLength;

// define the notes durations
int song_bpm = 120; 
int quarter = 60000 / song_bpm;
int dottedQuarter = quarter * 1.5;
int eighth = quarter / 2;
int dottedEighth = eighth * 1.5;
int half = 2 * quarter;
int dottedHalf = 3 * quarter;
int sixteenth = eighth / 2;

void lightLED(int row, int col) {
  int LEDPin = LEDPins[row][col];
  digitalWrite(LEDPin, HIGH);
  currentlyLitLEDs[row][0] = LEDPin;
  currentlyLitLEDs[row][1] = col;
}

void unlightLED(int row, int col) {
  int LEDPin = LEDPins[row][col];
  digitalWrite(LEDPin, LOW);
  currentlyLitLEDs[row][0] = 0;
  currentlyLitLEDs[row][1] = 0;
}

void reset() {
  for (int i = 0; i < numRows; i++)
    for (int j = 0; j < numCols; j++)
      digitalWrite(LEDPins[i][j], LOW);

  gameState = 0;
}

void playGame() {
  int BCButtonMappings[75] = {0, 1, 3, 0, 1, -1, -1, -1, 0, 1, 3, 0, 1, -1, -1, -1, 
  0, 1, 3, 0, -1, 
  3, 1, 0, -1, 3, 1, 
  0, -1, 0, -1, 0, -1, // CIAO CIAO CIAO
  2, 0, 1, 1, -1, -1, -1,
  1, 0, 2, 1, 0, -1, -1, -1, -1, 
  
  0, 2, 0, -1, 3, -1, 0, -1, 3, -1, 0, -1, 1, -1};
  int currentIndex = 0;

  while (BCButtonMappings[currentIndex] == -1)
    currentIndex++;

  // currentIndex now points to the first note
  lightLED(0, BCButtonMappings[currentIndex]);
  currentIndex++;

  Wire.beginTransmission(2);
  Wire.write(7); // arbitrary message to trigger 
  Wire.endTransmission();
  
  delay(eighth);

  for(int i = currentIndex; i < sizeof(BCButtonMappings) / sizeof(BCButtonMappings[0]); i++) {
    for (int j = numRows - 1; j >= 0; j--) {
      if (currentlyLitLEDs[j][0] != 0) {
        // There is currently an LED lit, shift it down
        int thisLEDCol = currentlyLitLEDs[j][1];
        unlightLED(j, thisLEDCol);
        if (j < numRows - 1)
          lightLED(j + 1, thisLEDCol);
      }
    }

    int noteToAdd = BCButtonMappings[i];
    if (noteToAdd != -1)
      lightLED(0, noteToAdd);

    delay(eighth);
  }

  reset();
}

void setup() {
  Wire.begin(); // Join as master
  
  Serial.begin(9600);
  
  // Initialize LEDs and Piezo as outputs
  pinMode(BuzzerPin, OUTPUT);
  for (int i = 0; i < numRows; i++)
    for (int j = 0; j < numCols; j++)
      pinMode(LEDPins[i][j], OUTPUT);

  gameState = 0;
}

void loop() { 
  if(gameState == 1){
    playGame();
  } else {
    Wire.requestFrom(2, 4);
    int song = Wire.read();
  
    while(Wire.available())
      Wire.read();
      
    if (song > 0) {
      gameState = 1;
    }
  }
}
