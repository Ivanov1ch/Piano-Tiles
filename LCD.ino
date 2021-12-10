// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// buttons config
int button1Pin = 6;
int button2Pin = 7;
int button3Pin = 8;
int button4Pin = 9;

int button1State = HIGH;
int button2State = HIGH;
int button3State = HIGH;
int button4State = HIGH;


void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);  
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  
  
}

int gameState = 0;

void loop() {
  switch(gameState) {
    case 0: 
      mainMenu();
      break;
    case 1:
      pickSong();
      break;
//    case 2: 
//    playGame();
//    break;
  }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):

  
  
}

void mainMenu() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  
  lcd.print("Welcome! Press");
  lcd.setCursor(0, 1);
  lcd.print("button to start ");

  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  button4State = digitalRead(button4Pin);
  
  

  if (button1State == LOW || button2State == LOW || button3State == LOW || button4State == LOW) {
    
    resetScreen();
    gameState = 1;
    delay(500);
  
 
  }
  
}



void pickSong() {
  
  lcd.print("White: Toxic");
  lcd.setCursor(0, 1);
  lcd.print("Blue: BellaCiao ");

  
  
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin); 

  if (button2State == LOW) {
    resetScreen();
    lcd.print("Playing");
    lcd.setCursor(0, 1);
    lcd.print("Bella Ciao");
    delay(2000);
    resetScreen();
    gameState = 0;
    
    
  }

  else if (button1State == LOW) {
    resetScreen();
    lcd.print("Playing Toxic");
    delay(2000);
    resetScreen();
    gameState = 0;
  }
   
}

void resetScreen() {
  lcd.setCursor(0,0);
  lcd.print("                 ");
  lcd.setCursor(0,1);
  lcd.print("                 ");
  lcd.setCursor(0,0);
}
