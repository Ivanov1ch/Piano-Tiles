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

const int bpm = 120;

const int quarter = 60000 / bpm;
const int dottedQuarter = quarter * 1.5;
const int eighth = quarter / 2;
const int dottedEighth = eighth * 1.5;
const int half = 2 * quarter;
const int dottedHalf = 3 * quarter;
const int sixteenth = eighth / 2;

const int lenBC = 44;

const int BellaCiao[lenBC][3] = {
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



int BCButtonMappings[75] = {0, 1, 3, 0, 1, -1, -1, -1, 0, 1, 3, 0, 1, -1, -1, -1, 
0, 1, 3, 0, -1, 3, 1, 0, -1, 3, 1, 0, 0, 0, 2, 0, 1, 1, -1, -1, -1, -1, -1, 1, 0,
2, 1, 0, -1, -1, -1, -1, -1, 0, 2, 0, 3, -1, 0, -1, 3, -1, 0, -1, 1, -1, -1, -1, -1,
-1, -1, -1, -1, -1};
