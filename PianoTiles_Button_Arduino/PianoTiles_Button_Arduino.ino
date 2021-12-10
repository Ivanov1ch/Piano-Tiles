#include <Wire.h>
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int numButtons = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Order: same as columns, from left to right (green, blue, yellow, white)
const int buttonPins[numButtons] = {8, 9, 7, 6}; // black, blue, yellow, white
int buttonStatuses[numButtons] = {0,0,0,0};

int gameState = 0;

void updateButtons() {
  for(int i = 0; i < numButtons; i++)
    buttonStatuses[i] = HIGH - digitalRead(buttonPins[i]);
}

void pickSong() {
  lcd.print("Black:BellaChio"); //index 0 in array
  lcd.setCursor(0, 1); 
  lcd.print("Blue: Toxic"); //index 1 in array
  
  if(buttonStatuses[0]) { // play Bella Ciao
    resetScreen();
    lcd.print("Playing");
    lcd.setCursor(0, 1);
    lcd.print("Bella Ciao");
    delay(2500);
    gameState = 2;
  }

  if(buttonStatuses[1]) { // play Toxic
    resetScreen();
    lcd.print("Playing Toxic");
    delay(2500);
    gameState = 2;
  }
}

void playGame() {
  // idle
}

void resetScreen() {
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,0);
}

void startScreen() {
  // Code that greets user and updates user on which was pressed

  lcd.setCursor(0, 0);
  lcd.print("Welcome! Press");
  lcd.setCursor(0, 1);
  lcd.print("button to start");

  for (int i=0; i<numButtons; ++i) {
      if(buttonStatuses[i] == HIGH) {
        resetScreen();
        gameState = 1;
        delay(200);
     }
  }
}

void sendButtonConfig(int numBytes) {
  for (int i = 0; i < numButtons; i++) {
    Wire.write(HIGH - digitalRead(buttonPins[i]));
  }
}

void setup() {
  Wire.begin(2);
  Wire.onRequest(sendButtonConfig);
  
  lcd.begin(16, 2);  
  
  Serial.begin(9600);

  for(int i = 0; i < numButtons; i++)
    pinMode(buttonPins[i], INPUT);

}

void loop() {
  updateButtons();
  switch(gameState) {
    case 0: 
      startScreen();
      break;
    case 1:
      pickSong();
      break;
    case 2: 
      playGame();
      break;
  }
}
