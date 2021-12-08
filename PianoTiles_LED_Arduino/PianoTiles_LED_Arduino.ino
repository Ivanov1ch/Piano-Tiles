#include <Wire.h>

// Order within each array: leftmost column (green) to rightmost column (white)
// Arrays are ordered with rows: top to bottom (red)
const int LEDPins[4][4] = {{13, 12, 11, 10}, {9, 8, 7, 6}, {5, 4, 3, 2}, {A0, A1, A2, A3}};
const int numRows = sizeof(LEDPins)/sizeof(LEDPins[0]);
const int numCols = sizeof(LEDPins[0])/sizeof(LEDPins[0][0]);

int rowProgression[13] = {3, 2, 2, 1, 0, -1, -1, 2, -1, 3, 2, 1, 0};
int currentlyLitLEDs[numRows][2] = {};
int rowsShown = 0, rowsCleared = 0, numRests = 0, progressionLen = sizeof(rowProgression) / sizeof(rowProgression[0]);
bool isFirstNote = true;

int buttonStates[numCols] = {};
bool newButtonData = false;

void setup() {
  Serial.begin(9600);
  Wire.begin(0x2);
  Wire.onReceive(gotButtonStatus);

  // Initialize LEDs as outputs
  for (int i = 0; i < numRows; i++)
    for (int j = 0; j < numCols; j++)
      pinMode(LEDPins[i][j], OUTPUT);
}

void gotButtonStatus(int numBytes) {
  Serial.println("Receieved");
  for(int i = 0; i < numCols; i++)
    buttonStates[i] = Wire.read();
  newButtonData = true;
}

void loop() {
  if (isFirstNote) {
    lightLED(0, rowProgression[rowsShown]);
    isFirstNote = false;
  } else {
    // Shift all currently-lit LEDs down one row
    for (int i = numRows - 1; i >= 0; i--)
      if (currentlyLitLEDs[i][0] != 0) {
        // There is currently an LED lit, shift it down
        int thisLEDCol = currentlyLitLEDs[i][1];
        unlightLED(i, thisLEDCol);
        if (i < numRows - 1) {
          lightLED(i + 1, thisLEDCol);
        } else {
          rowsCleared++;
        }
      }

    // Add the next note
    int noteToAdd;
    if(rowsShown < progressionLen) {
      noteToAdd = rowProgression[rowsShown];
      if (noteToAdd == -1) {
        numRests++;
      }   
    } else 
      noteToAdd = -1;
    // Add note if it's not a rest
    if (noteToAdd != -1)
      lightLED(0, noteToAdd);
  }

  if (newButtonData) {
    Serial.println(String(buttonStates[0]) + ", " + String(buttonStates[1]) + ", " + String(buttonStates[2]) + ", " + String(buttonStates[3]));
    newButtonData = false;
  }
  
  delay(1000);

  if(rowsShown < progressionLen)
    rowsShown++;
  else if(rowsCleared + numRests == progressionLen) {
    // Game is done, reset
    rowsShown = 0;
    rowsCleared = 0;
    numRests = 0;
    isFirstNote = true;
  }
}

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

bool allReleased() {  
  // Request button statuses
  Wire.requestFrom(1, numCols);
  for (int i = 0; i < numCols; i++)
    if(Wire.read() == HIGH)
      return false;
  return true;
}

bool buttonIsPressed(int buttonIndex) {
  // Init array of 0s (all unpressed)
  int buttonStatuses[numCols] = {};
  // Request button statuses
  Wire.requestFrom(1, numCols);
  for (int i = 0; i < numCols; i++)
    buttonStatuses[i] = Wire.read();

  // buttonStatuses now has the status of the button corresponding to each column of lights, in the same index order as in LEDPins
  return buttonStatuses[buttonIndex] == HIGH;
}
