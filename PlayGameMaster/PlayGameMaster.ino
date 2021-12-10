#include <Wire.h>

const int BuzzerPin = 12;
const int LEDPins[4][4] = {{1, 13, 11, 10}, {9, 8, 7, 6}, {5, 4, 3, 2}, {A0, A1, A2, A3}};
const int numRows = sizeof(LEDPins)/sizeof(LEDPins[0]);
const int numCols = sizeof(LEDPins[0])/sizeof(LEDPins[0][0]);

const int numSongs = 2;

int rowProgression[13] = {3, 2, 2, 1, 0, -1, -1, 2, -1, 3, 2, 1, 0};
int currentlyLitLEDs[numRows][2] = {};
int rowsShown = 0, rowsCleared = 0, numRests = 0, progressionLen = sizeof(rowProgression) / sizeof(rowProgression[0]);
bool isFirstNote = true;

int gameState, chosenSong, chosenSongLength;

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

// define the notes durations
int half, dottedHalf, quarter, dottedQuarter, eighth, dottedEighth, sixteenth;

int bella_ciao_bpm = 120; 
int toxic_bpm = 144;

void defineNoteDurations(int song_bpm) {
  quarter = 60000 / song_bpm;
  dottedQuarter = quarter * 1.5;
  eighth = quarter / 2;
  dottedEighth = eighth * 1.5;
  half = 2 * quarter;
  dottedHalf = 3 * quarter;
  sixteenth = eighth / 2;
  // THIS VARIABLE SHOULD BE TIME BETWEEN LED's flashing
}

void playGame() {
  defineNoteDurations(chosenSong == 1 ? bella_ciao_bpm : toxic_bpm);
  
  int BellaCiao[44][3] = {
    {NE5, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {NB5, eighth, eighth + 50}, {NC6, eighth, eighth + 50},
    {NA5, eighth, eighth + 50}, {REST, dottedQuarter, 0}, {NE5, eighth, eighth + 50}, {NA5, eighth, eighth + 50},
    {NB5, eighth, eighth + 50}, {NC6, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {REST, dottedQuarter, 0},

    {NE5, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {NB5, eighth, eighth + 50}, {NC6, quarter, quarter + 50}, // last one is 1.3. CIAO
    {NB5, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {NC6, quarter, quarter + 50},
    {NB5, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {NE6, eighth, quarter + 50}, {NE6, eighth, quarter + 50}, {NE6, eighth, quarter + 50}, // CIAO CIAO CIAO. 24 notes
    {ND6, eighth, eighth + 50}, {NE6, eighth, eighth + 50}, {NF6, eighth, eighth + 50}, {NF6, quarter, quarter + 50}, {REST, half, 0},
    {NF6, eighth, eighth + 50}, {NE6, eighth, eighth + 50}, {ND6, eighth, eighth + 50}, {NF6, eighth, eighth + 50}, {NE6, quarter, quarter + 50}, {REST, half, 0},
    {NE6, eighth, eighth + 50}, {ND6, eighth, eighth + 50}, {NC6, eighth, eighth + 50}, {NB5, quarter, quarter + 50}, {NE6, quarter, quarter + 50}, {NB5, quarter, quarter + 50}, {NC6, quarter, quarter + 50},
    {NA5, half, half + 50}, {REST, 2 * half, 0}
  };
  int Toxic[260][3] = {
    {NC4, eighth, eighth + 50}, {NC4, eighth, eighth + 50}, {NDS4, sixteenth, sixteenth + 25}, {ND4, sixteenth, sixteenth + 25}, {NC4, sixteenth, sixteenth + 25},
    {ND4, sixteenth, sixteenth + 25}, {NDS4, dottedEighth, dottedEighth + 50}, {NC4, sixteenth, sixteenth + 25}, {NDS4, sixteenth, sixteenth + 25}, {ND4, sixteenth, sixteenth + 25},
    {NC4, eighth, eighth + 50}, {NFS6, quarter, quarter + 50}, {ND6, quarter, quarter + 50}, {NDS6, eighth, eighth + 50}, {ND6, eighth, eighth + 50},
    {NC6, quarter, quarter + 50}, //16
    {NC4, eighth, eighth + 50}, {NC4, eighth, eighth + 50}, {NDS4, sixteenth, sixteenth + 25}, {ND4, sixteenth, sixteenth + 25}, {NC4, sixteenth, sixteenth + 25},
    {ND4, sixteenth, sixteenth + 25}, {NDS4, dottedEighth, dottedEighth + 50}, {NC4, sixteenth, sixteenth + 25}, {NDS4, sixteenth, sixteenth + 25}, {ND4, sixteenth, sixteenth + 25},
    {NC4, eighth, eighth + 50}, {NFS6, quarter, quarter + 50}, {ND6, quarter, quarter + 50}, {NDS6, eighth, eighth + 50}, {ND6, eighth, eighth + 50},
    {NC6, quarter, quarter + 50}, //32

    {NC5, eighth, eighth + 50}, {NC5, eighth, eighth + 50}, {NDS5, sixteenth, sixteenth + 25}, {ND5, sixteenth, sixteenth + 25}, {NC5, sixteenth, sixteenth + 25},
    {ND5, sixteenth, sixteenth + 25}, {NDS5, dottedEighth, dottedEighth + 50}, {NC5, sixteenth, sixteenth + 25}, {NDS5, sixteenth, sixteenth + 25}, {ND5, sixteenth, sixteenth + 25},
    {NC5, eighth, eighth + 50}, {NFS6, quarter, quarter + 50}, {ND6, quarter, quarter + 50}, {NDS6, eighth, eighth + 50}, {ND6, eighth, eighth + 50},
    {NC6, quarter, quarter + 50},
    {NC5, eighth, eighth + 50}, {NC5, eighth, eighth + 50}, {NDS5, sixteenth, sixteenth + 25}, {ND5, sixteenth, sixteenth + 25}, {NC5, sixteenth, sixteenth + 25},
    {ND5, sixteenth, sixteenth + 25}, {NDS5, dottedEighth, dottedEighth + 50}, {NC5, sixteenth, sixteenth + 25}, {NDS5, sixteenth, sixteenth + 25}, {ND5, sixteenth, sixteenth + 25},
    {NC5, eighth, eighth + 50}, {NFS6, quarter, quarter + 50}, {ND6, quarter, quarter + 50}, {NDS6, eighth, eighth + 50}, {ND6, eighth, eighth + 50},
    {NC6, quarter, quarter + 50}, //64

    //Bar 9
    {REST, quarter + 50, 0}, {NC4, eighth, eighth + 50}, {ND4, eighth, eighth + 50}, {NDS4, eighth, eighth + 50}, {ND4, eighth, eighth + 50}, {NC4, quarter, quarter + 50},
    {REST, dottedQuarter, 0}, {NC4, eighth, eighth + 50}, {NDS4, eighth, eighth + 50}, {NC4, eighth, eighth + 50}, {NDS4, half, half + 50}, {REST, eighth, 0},
    {NC4, eighth, eighth + 50}, {NDS4, eighth, eighth + 50}, {ND4, eighth, eighth + 50}, {NC4, quarter, quarter + 50}, {REST, eighth, 0}, //83 notes
    {NC4, eighth, eighth + 50}, {NC4, eighth, eighth + 50}, {NC4, eighth, eighth + 50}, {NDS4, eighth, eighth + 50}, {NC4, eighth, eighth + 50}, {NDS4, half, half + 50},
    {REST, eighth, 0}, {NAS3, eighth, eighth + 50}, {ND4, eighth, eighth + 50}, {NC4, eighth, eighth + 50}, {NAS3, quarter, quarter + 50}, {REST, dottedQuarter, 0}, //95

    // Bar 14th
    {NG3, eighth, eighth + 50}, {NB3, eighth, eighth + 50}, {NG3, eighth, eighth + 50}, {NB3, quarter, quarter + 50},
    {NC5, eighth, eighth + 50}, {NC5, eighth, eighth + 50}, {NDS5, sixteenth, sixteenth + 25}, {ND5, sixteenth, sixteenth + 25}, {NC5, sixteenth, sixteenth + 25}, //104
    {ND5, sixteenth, sixteenth + 25}, {NDS5, dottedEighth, dottedEighth + 50}, {NC5, sixteenth, sixteenth + 25}, {NDS5, sixteenth, sixteenth + 25}, {ND5, sixteenth, sixteenth + 25},
    {NC5, eighth, eighth + 50}, {NFS6, quarter, quarter + 50}, {ND6, quarter, quarter + 50}, {NDS6, eighth, eighth + 50}, {ND6, eighth, eighth + 50},
    {NC6, quarter, quarter + 50}, {REST, quarter + 50, 0}, //116

    // At bar 17, Bar 9 repeated one octave higher
    {NC5, eighth, eighth + 50}, {ND5, eighth, eighth + 50}, {NDS5, eighth, eighth + 50}, {ND5, eighth, eighth + 50}, {NC5, quarter, quarter + 50},
    {REST, dottedQuarter, 0}, {NC5, eighth, eighth + 50}, {NDS5, eighth, eighth + 50}, {NC5, eighth, eighth + 50}, {NDS5, half, half + 50}, {REST, eighth, 0},
    {NC5, eighth, eighth + 50}, {NDS5, eighth, eighth + 50}, {ND5, eighth, eighth + 50}, {NC5, quarter, quarter + 50}, {REST, eighth, 0},
    {NC5, eighth, eighth + 50}, {NC5, eighth, eighth + 50}, {NC5, eighth, eighth + 50}, {NDS5, eighth, eighth + 50}, {NC5, eighth, eighth + 50}, {NDS5, half, half + 50},
    {REST, eighth, 0}, {NAS4, eighth, eighth + 50}, {ND5, eighth, eighth + 50}, {NC5, eighth, eighth + 50}, {NAS4, quarter, quarter + 50}, {REST, dottedQuarter, 0},

    {NG4, eighth, eighth + 50}, {NB4, eighth, eighth + 50}, {NG4, eighth, eighth + 50}, {NB4, quarter, quarter + 50},
    {NC5, eighth, eighth + 50}, {NC5, eighth, eighth + 50}, {NDS5, sixteenth, sixteenth + 25}, {ND5, sixteenth, sixteenth + 25}, {NC5, sixteenth, sixteenth + 25},
    {ND5, sixteenth, sixteenth + 25}, {NDS5, dottedEighth, dottedEighth + 50}, {NC5, sixteenth, sixteenth + 25}, {NDS5, sixteenth, sixteenth + 25}, {ND5, sixteenth, sixteenth + 25},
    {NC5, eighth, eighth + 50}, {NFS6, quarter, quarter + 50}, {ND6, quarter, quarter + 50}, {NDS6, eighth, eighth + 50}, {ND6, eighth, eighth + 50},
    {NC6, quarter, quarter + 50}, {REST, quarter + 50, 0}, // 168

    // Bar 25: TOO high, cant come down
    {NG5, quarter, quarter + 50}, {NA5, quarter, quarter + 50}, {REST, quarter, 0}, 
    {NAS5, quarter, quarter + 50}, {NF6, quarter, quarter + 50}, {NA5, quarter, quarter + 50}, {NG5, quarter, quarter + 50},
    {REST, eighth, 0}, {NG5, eighth, eighth + 50}, {NG5, eighth, eighth + 50}, {NG5, eighth, eighth + 50}, {NA5, quarter, quarter + 50},
    {NA5, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {NAS5, quarter, quarter + 50}, 
    {NF6, quarter, quarter + 50}, {NA5, quarter, quarter + 50}, {NG5, quarter, quarter + 50}, {REST, 2*half, 0},

    // Bar 30, can you hear me now
    {REST, quarter, 0}, {NF5, eighth, eighth + 50}, {NG5, eighth, eighth + 50}, {NAS5, eighth, eighth + 50}, {NG5, eighth, eighth + 50}, {NF5, quarter, quarter + 50},
    {NC5, eighth, eighth + 50}, {NC5, eighth, eighth + 50}, {NDS5, sixteenth, sixteenth + 25}, {ND5, sixteenth, sixteenth + 25}, {NC5, sixteenth, sixteenth + 25},
    {ND5, sixteenth, sixteenth + 25}, {NDS5, dottedEighth, dottedEighth + 50}, {NC5, sixteenth, sixteenth + 25}, {NDS5, sixteenth, sixteenth + 25}, {ND5, sixteenth, sixteenth + 25},
    {NC5, eighth, eighth + 50}, {NFS6, quarter, quarter + 50}, {ND6, quarter, quarter + 50}, {NDS6, eighth, eighth + 50}, {ND6, eighth, eighth + 50},
    {NC6, quarter, quarter + 50}, 

    //HYPE BUILDUP
    {NC3, eighth, eighth + 50}, {NC3, eighth, eighth + 50}, {NC3, eighth, eighth + 50}, {NC3, eighth, eighth + 50}, 
    {NC3, eighth, eighth + 50}, {NC3, eighth, eighth + 50}, {NC3, eighth, eighth + 50}, {NC3, eighth, eighth + 50}, 
    {NC3, eighth, eighth + 50}, {NC3, eighth, eighth + 50}, {NC3, eighth, eighth + 50}, {NC3, eighth, eighth + 50}, 
    {NC3, eighth, eighth + 50}, {NC3, eighth, eighth + 50}, {NG4, eighth, eighth + 50}, {NAS4, eighth, eighth + 50}, 
    
    // Bar 35: Chorus: Taste of your lips, I'm on a ride
    {ND4, quarter, quarter + 50}, {NC4, eighth, eighth + 50}, {NAS4, eighth, eighth + 50}, {NAS4, quarter, quarter + 50}, {NG4, quarter, quarter + 50}, 
    {NF4, eighth, eighth + 50}, {NDS4, eighth, eighth + 50}, {NAS4, dottedHalf, dottedHalf + 50}, 
    {REST, quarter, 0}, {NC5, quarter, quarter+50}, {NG4, quarter, quarter+50}, {NC5, quarter, quarter+50}, //You're Tox Ic
    {NG4, quarter, quarter+50}, {NC5, eighth, eighth+50}, {NC5, eighth, eighth+50}, {NG4, quarter, quarter+50}, {NG4, eighth, eighth+50}, {NAS4, eighth, eighth+50},

    {ND4, quarter, quarter + 50}, {NC4, eighth, eighth + 50}, {NAS4, eighth, eighth + 50}, {NAS4, quarter, quarter + 50}, {NG4, quarter, quarter + 50}, 
    {NF4, eighth, eighth + 50}, {NDS4, eighth, eighth + 50}, {NAS4, half, half + 50}, {NC4, eighth, eighth+50}, {NDS4, eighth, eighth+50},
    {NFS4, quarter, quarter+50}, {NF4, eighth, eighth + 50}, {NDS4, eighth, eighth + 50}, {NDS4, quarter, quarter + 50}, {NC4, eighth, eighth + 50}, {NDS4, eighth, eighth + 50},
    {NFS4, quarter, quarter+50}, {NF4, eighth, eighth + 50}, {NDS4, eighth, eighth + 50}, {NF4, quarter, quarter+50}, {NG4, quarter, quarter+50},
    
    {NG5, quarter, 2*half},
  };

  int songToPlay[sizeof(chosenSong == 1 ? BellaCiao : Toxic) / sizeof((chosenSong == 1 ? BellaCiao : Toxic)[0])][sizeof((chosenSong == 1 ? BellaCiao : Toxic)[0]) / sizeof((chosenSong == 1 ? BellaCiao : Toxic)[0][0])];

  for(int i = 0; i < sizeof(songToPlay) / sizeof(songToPlay[0]); i++)
    for(int j = 0; j < sizeof(songToPlay[0]) / sizeof(songToPlay[0][0]); j++)
      songToPlay[i][j] = (chosenSong == 1 ? BellaCiao : Toxic)[0][0];

  chosenSongLength = sizeof(songToPlay) / sizeof(songToPlay[0]);
  
  for (int i = 0; i < chosenSongLength; i++) {
    if (songToPlay[i][0] == REST) {
      int dur = songToPlay[i][1];
      delay(dur);
    } else {
      int note = songToPlay[i][0]; 
      int dur = songToPlay[i][1];
      tone(BuzzerPin, note, dur);
      delay(dur);
    }
  }
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
        
    Serial.println(song);
      
    if (song > 0) {
      chosenSong = song;
      gameState = 1;
    }
  }
}

void playSong1() {
  Serial.println("Song 1");
  delay(1000);
}

void playSong2() {
  Serial.println("Song 2");
  delay(1000);
}
