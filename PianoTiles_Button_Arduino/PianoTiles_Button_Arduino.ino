#include <Wire.h>
#include <LiquidCrystal.h>

int menuState = 0;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int numButtons = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Order: same as columns, from left to right (green, blue, yellow, white)
const int buttonPins[numButtons] = {A3, A2, A1, A0}; // black, blue, yellow, white
int buttonStatuses[numButtons] = {0,0,0,0};

const int BuzzerPin = 8;

int chosenSong = 0;

// SONG STUFF
const int REST = 100; // has to be unique

// 3rd Octave
const int NC3 = 131; const int NCS3 = 138; const int ND3 = 147; const int NDS3 = 155;
const int NE3 = 165; const int NF3 = 175; const int NFS3 = 185; const int NG3 = 196;
const int NGS3 = 208; const int NA3 = 220; const int NAS3 = 233; const int NB3 = 247;

// 4th Octave (middle C)
int NC4 = 262; int NCS4 = 277; int ND4 = 294;
int NDS4 = 311; int NE4 = 330; int NF4 = 349;
int NFS4 = 370; int NG4 = 392; int NGS4 = 415;
int NA4 = 440; int NAS4 = 466; int NB4 = 494;

// 5th Octave
int NB5 = 988; int NAS5 = 932; int NA5 = 880;
int NGS5 = 830; int NG5 = 784; int NFS5 = 740;
int NF5 =  698; int NE5 =  659; int NDS5 = 622;
int ND5 = 587; int NCS5 = 554; int NC5 = 523;

// 6th Octave

int NB6 = 1975; int NAS6 = 1865; int NA6 = 1760;
int NGS6 = 1661; int NG6 = 1568; int NFS6 = 1480;
int NF6 = 1397; int NE6 = 1318; int NDS6 = 1244;
int ND6 = 1175; int NCS6 = 1109; int NC6 = 1046;

int song_bpm = 120; 
int quarter = 60000 / song_bpm;
int dottedQuarter = quarter * 1.5;
int eighth = quarter / 2;
int dottedEighth = eighth * 1.5;
int half = 2 * quarter;
int dottedHalf = 3 * quarter;
int sixteenth = eighth / 2;

int BellaCiao[44][3] = {
    {NE5, eighth, eighth}, {NA5, eighth, eighth}, {NB5, eighth, eighth}, {NC6, eighth, eighth},
    {NA5, eighth, eighth}, {REST, dottedQuarter}, {NE5, eighth, eighth}, {NA5, eighth, eighth},
    {NB5, eighth,}, {NC6, eighth, eighth}, {NA5, eighth, eighth}, {REST, dottedQuarter, 0}, {REST, quarter,0},

    {NE5, eighth, eighth}, {NA5, eighth, eighth}, {NB5, eighth, eighth}, {NC6, quarter, quarter}, // last one is 1.3. CIAO
    {NB5, eighth, eighth}, {NA5, eighth, eighth}, {NC6, quarter, quarter},
    {NB5, eighth, eighth}, {NA5, eighth, eighth}, {NE6, quarter, quarter}, {NE6, quarter, quarter}, {NE6, quarter, quarter}, // CIAO CIAO CIAO. 24 notes
  
    {ND6, eighth, eighth}, {NE6, eighth, eighth}, {NF6, eighth, eighth}, {NF6, dottedQuarter, dottedQuarter}, {REST, eighth, 0},
    {NF6, eighth, eighth }, {NE6, eighth, eighth}, {ND6, eighth, eighth}, {NF6, eighth, eighth}, {NE6, dottedQuarter,dottedQuarter}, {REST, quarter, 0},
    
    {ND6, eighth, eighth}, {NC6, eighth, eighth}, {NB5, quarter, quarter}, {NE6, quarter, quarter}, {NB5, quarter, quarter}, {NC6, quarter, quarter},
    {NA5, half, half}
  };


void reset() {
  noTone(BuzzerPin);
  resetScreen();
  menuState = 0;
  delay(1500);
}

int timeToStartPlaying;

// THIS VARIABLE SHOULD BE TIME BETWEEN LED's flashing
void startPlaying(int numBytes) { //bound to onReceive()
  Wire.read();
  timeToStartPlaying = millis() + 4 * eighth;
  Serial.println(timeToStartPlaying);
  menuState = 3;
}

void updateButtons() {
  for(int i = 0; i < numButtons; i++) {
    if (i != 2)
      buttonStatuses[i] = HIGH - digitalRead(buttonPins[i]);
    else 
      buttonStatuses[i] = digitalRead(buttonPins[i]);
  }
}

void pickSong() {
  lcd.print("Black:"); //index 0 in array
  lcd.setCursor(0, 1); 
  lcd.print("Bella Ciao      "); //index 1 in array
  
  if(buttonStatuses[0]) { // play Bella Ciao
    chosenSong = 1;
    menuState = 2;
    resetScreen();
    lcd.print("Playing");
    lcd.setCursor(0, 1);
    lcd.print("Bella Ciao");
  }
}

void playGame() { //menuState is 3, triggered by startPlaying
  while(millis() < timeToStartPlaying)
    Serial.println(String(millis()) + ", " + timeToStartPlaying);
  
  for (int i = 0; i < 44; i++) {
    if (BellaCiao[i][0] == REST) {
      int dur = BellaCiao[i][1];
      delay(dur);
    } else {
      int note = BellaCiao[i][0]; 
      int dur = BellaCiao[i][1];
      tone(BuzzerPin, note, dur);
      delay(BellaCiao[i][2]);
    }
  }

  reset();
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
        menuState = 1; 
     }
  }
}

void sendButtonConfig(int numBytes) { //bound to onRequest
  if (numBytes == 4) {
    if (menuState == 2) {
      Wire.write(chosenSong); // Tell the main Arduino that we are ready to play
    } else {
      Wire.write(0);
    }
  } else if (numBytes == 16)
    for (int i = 0; i < numButtons; i++)
      Wire.write(HIGH - digitalRead(buttonPins[i]));
  
}

void setup() {
  Wire.begin(2);
  Wire.onRequest(sendButtonConfig);
  Wire.onReceive(startPlaying);
  
  lcd.begin(16, 2);  
  
  Serial.begin(9600);

  for(int i = 0; i < numButtons; i++)
    pinMode(buttonPins[i], INPUT);

  menuState = 0;
}

void loop() {
  updateButtons();
  Serial.println(String(millis()) + ", " + buttonStatuses[0] + ", " + buttonStatuses[1] + ", " + buttonStatuses[2] + ", " + buttonStatuses[3]);
  if(menuState == 0)
      startScreen();
  else if (menuState == 1)
      pickSong();
  else if (menuState == 3) 
      playGame();
}
