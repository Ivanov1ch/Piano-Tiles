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

void setup() {
  Wire.begin(1); //declare as slave

  for(int i = 0; i < numButtons; i++)
    pinMode(buttonPins[i], INPUT);

  Wire.onReceive(startScreen);

  
}

int gameState = 0;

void loop() {
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

void startScreen(int numbytes) {
  // Code that greets user and updates user on which was pressed

  lcd.setCursor(0, 0);
  lcd.print("Welcome! Press");
  lcd.setCursor(0, 1);
  lcd.print("button to start");

  for (int i=0; i<numButtons; ++i) {
     int valueRead = digitalRead(buttonPins[i]);
     buttonStatuses[i] = HIGH - valueRead;
  }
  for (int i=0; i<numButtons; ++i) {
      if(buttonStatuses[i] == HIGH) {
        resetScreen();
        gameState = 1;
        delay(200);
         
     }
}

void pickSong() {
  lcd.print("Black:BellaChio"); //index 0 in array
  lcd.setCursor(0, 1); 
  lcd.print("Blue: Toxic "); //index 1 in array
  
  button1State = HIGH - digitalRead(buttonPins[0]);
  button2State = HIGH - digitalRead(buttonPins[1]); 

  if(button1State == HIGH) { // play Bella Ciao
    buttonStatuses[0] = button1State;
    resetScreen();
    lcd.print("Playing");
    lcd.setCursor(0, 1);
    lcd.print("Bella Ciao");
  }
    
  }

  if(button2State == HIGH) { // play Toxic
    buttonStatuses[0] = button1State;
    resetScreen();
    lcd.print("Playing Toxic");
    
  }

  for (int i=0; i<numButtons; ++i) {
   int valueRead = digitalRead(buttonPins[i]);
   buttonStatuses[i] = HIGH - valueRead;
   if(buttonStatuses[i] == HIGH) {
    resetScreen();
    lcd.print("button "); lcd.print(i+1); lcd.print("is");
    lcd.setCursor(0, 1);
    lcd.print("pressed");
    
    delay(1000);    
   }
}

  Wire.beginTransmission(0);
  for(int stat:buttonStatuses) {
    Wire.write(stat);
  }
  Wire.endTransmission();
}

void resetScreen() {
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,0);
}

void sendButtons(int numbytes) {
  
  Wire.beginTransmission(0);
  for(int buttonPin:buttonPins) {
    Wire.write(HIGH - digitalRead(buttonPin));
  }
  Wire.endTransmission();
}
