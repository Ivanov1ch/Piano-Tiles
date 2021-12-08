int BuzzerPin = 11;     // Connect Buzzer to Arduino pin 11

// Frquencies: https://pages.mtu.edu/~suits/notefreqs.html

int REST = 100; // has to be unique

// 3rd Octave
int NC3 = 131; int NCS3 = 138; int ND3 = 147; int NDS3 = 155;
int NE3 = 165; int NF3 = 175; int NFS3 = 185; int NG3 = 196;
int GS3 = 208; int NA3 = 220; int NAS3 = 233; int NB3 = 247;

// 4th Octave (middle C)
int NC4 = 262; int NCS4 = 277; int ND4 = 294;
int NDS4 = 311; int NE4 = 330; int NF4 = 349;
int NFS4 = 370; int NG4 = 392; int NGS4 = 415;
int NNA4 = 440; int NAS4 = 466; int NB4 = 494;

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
int half = 0;
int dottedHalf = 0;
int quarter = 0;
int dottedQuarter = 0;
int eighth = 0;
int dottedEighth = 0;
int sixteenth = 0;
int dotted16th = 0;
int bpm = 144;

int BellaCiao[44][3];

void setup() {
  pinMode(BuzzerPin, OUTPUT);
  Serial.begin(9600);

  quarter = 60000 / bpm;
  dottedQuarter = quarter * 1.5;
  eighth = quarter / 2;
  dottedEighth = eighth * 1.5;
  half = 2 * quarter;
  dottedHalf = 3 * quarter;
  sixteenth = eighth / 2;
  dotted16th = 1.5 * sixteenth;
}
void loop() {
  // Note: {Note Value (N=Note, A = Note, 5 = 5th octave}; duration (quarter note,

  Serial.print("Starting the shebang");


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

  int sizeOfToxic = 266;
  // Link: https://musescore.com/user/14650376/scores/4998268

  int Toxic[sizeOfToxic][3] = {
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
    {REST, quarter, 0}, {NC5, quarter, quarter+50}, {NG5, quarter, quarter+50}, {NC5, quarter, quarter+50}, //You're Tox Ic
    {NG5, quarter, quarter+50}, {NC5, eighth, eighth+50}, {NC5, eighth, eighth+50}, {NG4, quarter, quarter+50}, {NG4, eighth, eighth+50}, {NAS4, eighth, eighth+50},

    {ND4, quarter, quarter + 50}, {NC4, eighth, eighth + 50}, {NAS4, eighth, eighth + 50}, {NAS4, quarter, quarter + 50}, {NG4, quarter, quarter + 50}, 
    {NF4, eighth, eighth + 50}, {NDS4, eighth, eighth + 50}, {NAS4, half, half + 50}, {NC4, eighth, eighth+50}, {NDS4, eighth, eighth+50},
    {NFS4, quarter, quarter+50}, {NF4, eighth, eighth + 50}, {NDS4, eighth, eighth + 50}, {NDS4, quarter, quarter + 50}, {NC4, eighth, eighth + 50}, {NDS4, eighth, eighth + 50},
    {NFS4, quarter, quarter+50}, {NF4, eighth, eighth + 50}, {NDS4, eighth, eighth + 50}, {NF4, quarter, quarter+50}, {NG4, quarter, quarter+50},
    
    {NG5, quarter, 2*half},
    
 
    
  };
  

  //tone(BuzzerPin, NA5, quarter);
  delay(1000);
  //Serial.print(REST==100);

  for (int i = 0; i < sizeOfToxic; i++) {
    if (Toxic[i][0] == REST) {
      delay(Toxic[i][1]);
    } else {
      tone(BuzzerPin, Toxic[i][0], Toxic[i][1]);

      delay(Toxic[i][2]);
    }
  }

  delay(2000);

  /*
    for(int i=0; i<44; i++) {
    if(BellaCiao[i][0] == REST) {
      delay(BellaCiao[i][1]);
    } else {
      tone(BuzzerPin, BellaCiao[i][0], BellaCiao[i][1]);

      delay(BellaCiao[i][2]);
    }
    }
  */

  Serial.print("NEW LOOPPPE");
  delay(6000);
}

int duration(int beat, int bpm) {
  // returns number of milliseconds a given beat length should be
  int result;
  result = beat * 1000 * (60 / bpm);
  return result;
}