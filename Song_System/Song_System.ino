//#include "Song1.h"

int BuzzerPin = 12;     // Connect Buzzer to Arduino pin 11

// Frquencies: https://pages.mtu.edu/~suits/notefreqs.html

int REST = 100; // has to be unique

// 3rd Octave
int NC3 = 131; int NCS3 = 138; int ND3 = 147; int NDS3 = 155;
int NE3 = 165; int NF3 = 175; int NFS3 = 185; int NG3 = 196;
int NGS3 = 208; int NA3 = 220; int NAS3 = 233; int NB3 = 247;

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
int half = 0;
int dottedHalf = 0;
int quarter = 0;
int dottedQuarter = 0;
int eighth = 0;
int dottedEighth = 0;
int sixteenth = 0;

int bpm = 120; // This should be good for playing difficulty, 
// even if less recognizable

int BellaCiao[44][3];



void setup() {
  pinMode(BuzzerPin, OUTPUT);
  //serial.begin(9600);

  quarter = 60000 / bpm;
  dottedQuarter = quarter * 1.5;
  eighth = quarter / 2;
  dottedEighth = eighth * 1.5;
  half = 2 * quarter;
  dottedHalf = 3 * quarter;
  sixteenth = eighth / 2;
  // THIS VARIABLE SHOULD BE TIME BETWEEN LED's flashing
}
void loop() {
  // Note: {Note Value (N=Note, A = Note, 5 = 5th octave}; duration (quarter note,

  //serial.println("Starting the shebang");


  int BellaCiao[44][3] = {
    {NE5, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {NB5, eighth, eighth + 50}, {NC6, eighth, eighth + 50},
    {NA5, eighth, eighth + 50}, {REST, dottedQuarter, 0}, {NE5, eighth, eighth + 50}, {NA5, eighth, eighth + 50},
    {NB5, eighth, eighth + 50}, {NC6, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {REST, dottedQuarter, 0}, //16

    {NE5, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {NB5, eighth, eighth + 50}, {NC6, quarter, quarter + 50}, // last one is 1.3. CIAO
    {NB5, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {NC6, quarter, quarter + 50}, //25
    {NB5, eighth, eighth + 50}, {NA5, eighth, eighth + 50}, {NE6, eighth, quarter + 50}, {NE6, eighth, quarter + 50}, {NE6, eighth, quarter + 50}, // CIAO CIAO CIAO. 24 notes
    {ND6, eighth, eighth + 50}, {NE6, eighth, eighth + 50}, {NF6, eighth, eighth + 50}, {NF6, quarter, quarter + 50}, {REST, half, 0}, //41
    {NF6, eighth, eighth + 50}, {NE6, eighth, eighth + 50}, {ND6, eighth, eighth + 50}, {NF6, eighth, eighth + 50}, {NE6, quarter, quarter + 50}, {REST, half, 0},
    {NE6, eighth, eighth + 50}, {ND6, eighth, eighth + 50}, {NC6, eighth, eighth + 50}, {NB5, quarter, quarter + 50}, {NE6, quarter, quarter + 50}, {NB5, quarter, quarter + 50}, {NC6, quarter, quarter + 50},
    {NA5, half, half + 50}, {REST, 2 * half, 0}

  };

  const int sizeOfToxic = 260;
  const int sizeOfBella = 44;
  // Link: https://musescore.com/user/14650376/scores/4998268



  int INPUT_MAPPINGS[105];

  //tone(BuzzerPin, NA5, quarter);
  ////serial.print(REST==100);
  int j = 0;
  int indexPointer = 0;

  for (int i = 0; i < sizeOfBella; i++) {
    if (BellaCiao[i][0] == REST) {
      int dur = BellaCiao[i][1];
      for (int j=0; j<(dur/eighth); ++j) {
        BUTTON_MAPPINGS[indexPointer++] = -1;
        //serial.println(BUTTON_MAPPINGS[indexPointer-1]);
      }
      delay(dur);
      
    } else {
      int note = BellaCiao[i][0]; int dur = BellaCiao[i][1];
      //tone(BuzzerPin, note, dur);
      BUTTON_MAPPINGS[indexPointer++] = getButton(note);
      //serial.println(BUTTON_MAPPINGS[indexPointer-1]);
      for (int j=1; j<(dur/eighth); ++j) {
        BUTTON_MAPPINGS[indexPointer++] = -1;
        ////serial.println(BUTTON_MAPPINGS[indexPointer-1]);
      }
      
     

      delay(BellaCiao[i][2]);
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

  //serial.print("NEW LOOOOPP");
  delay(6000);
}

int getButton(int noteVal) {
  // returns button value corresponding to note frequency
  int result;
  int button1[] = {NC3, NE3, NGS3, NC4, NE4, NGS4, NC5, NE5, NGS5, NC6, NE6, NGS6};
  int button2[] = {NCS3, NF3, NA3, NCS4, NF4, NA4, NCS5, NF5, NA5, NCS6, NF6, NA6};
  int button3[] = {ND3, NFS3, NAS3, ND4, NFS4, NAS4, ND5, NFS5, NAS5, ND6, NFS6, NAS6,};
  int button4[] = {NDS3, NG3, NB3, NDS4, NG4, NB4, NDS5, NG5, NB5, NDS6, NG6, NB6,};
  
  for (int i = 0; i < 12; i++) {
    if ( button1[i] == noteVal) return 0;
    if ( button2[i] == noteVal) return 1;
    if ( button3[i] == noteVal) return 2;
    if ( button4[i] == noteVal) return 3;
    
  }

  
  return result;
}
