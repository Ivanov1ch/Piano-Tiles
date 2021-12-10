#include <Wire.h>
#include <LiquidCrystal.h>

int menuState = 0;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int numButtons = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Order: same as columns, from left to right (green, blue, yellow, white)
const int buttonPins[numButtons] = {A0, A1, A2, A3}; // black, blue, yellow, white
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
    {NE5, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {NB5, eighth, eighth + 50}, {NC6, eighth, eighth + 50},
    {NA5, eighth, eighth + 50}, {REST, dottedQuarter, 0}, {NE5, eighth, eighth + 50}, {NA5, eighth, eighth + 50},
    {NB5, eighth, eighth + 50}, {NC6, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {REST, dottedQuarter, 0},

    {NE5, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {NB5, eighth, eighth + 50}, {NC6, quarter, quarter + 50}, // last one is 1.3. CIAO
    {NB5, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {NC6, quarter, quarter + 50},
    {NB5, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {NE6, quarter, quarter + 50}, {NE6, quarter, quarter + 50}, {NE6, quarter, quarter + 50}, // CIAO CIAO CIAO. 24 notes
  
    {ND6, eighth, eighth + 50}, {NE6, eighth, eighth + 50}, {NF6, eighth, eighth + 50}, {NF6, dottedQuarter, dottedQuarter + 50}, {REST, dottedQuarter, 0},
    {NF6, eighth, eighth + 50}, {NE6, eighth, eighth + 50}, {ND6, eighth, eighth + 50}, {NF6, eighth, eighth + 50}, {NE6, dottedQuarter,dottedQuarter  + 50}, {REST, quarter, 0},
    {ND6, eighth, eighth + 50}, {NC6, eighth, eighth + 50}, {NB5, quarter, quarter + 50}, {NE6, quarter, quarter + 50}, {NB5, quarter, quarter + 50}, {NC6, quarter, quarter + 50},
    {NA5, half, half + 50}, {REST, 2 * half, 0}
  };

int timeToStartPlaying;

// THIS VARIABLE SHOULD BE TIME BETWEEN LED's flashing
void startPlaying(int numBytes) {
  timeToStartPlaying = millis() + Wire.read();
  Serial.println(timeToStartPlaying);
  menuState = 3;
}

void updateButtons() {
  for(int i = 0; i < numButtons; i++) {
    buttonStatuses[i] = HIGH - digitalRead(buttonPins[i]);
  }
}

void pickSong() {
  lcd.print("Black:BellaChio"); //index 0 in array
  lcd.setCursor(0, 1); 
  lcd.print("Blue: Toxic"); //index 1 in array
  
  if(buttonStatuses[0]) { // play Bella Ciao
    chosenSong = 1;
    menuState = 2;
    resetScreen();
    lcd.print("Playing");
    lcd.setCursor(0, 1);
    lcd.print("Bella Ciao");
    delay(2500);
  }

  if(buttonStatuses[1]) { // play Toxic
    chosenSong = 2;
    menuState = 2;
    resetScreen();
    lcd.print("Playing Toxic");
    delay(2500);
  }
}

void playGame() {
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
        delay(200);
     }
  }
}

void sendButtonConfig(int numBytes) {
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
}

void loop() {
  updateButtons();
//  if(menuState == 0)
//      startScreen();
//  else if (menuState == 1)
//      pickSong();
//  else 
  if (menuState == 3) 
      playGame();
}
