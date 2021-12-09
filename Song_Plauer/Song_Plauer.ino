int BuzzerPin = 11;     // Connect Buzzer to Arduino pin 11

int Si2 =1975;
int LaS2=1864;
int La2= 1760;
int SolS2=1661;
int Sol2=1567;
int FaS2=1479;
int Fa2= 1396;
int Mi2= 1318;
int ReS2=1244;
int Re2= 1174;
int DoS2=1108;
int Do2= 1046;

// Low Octave
int Si = 987;
int LaS= 932;
int La = 880;
int SolS=830;
int Sol= 783;
int FaS= 739;
int Fa=  698;
int Mi=  659;
int ReS= 622;
int Re = 587;
int DoS =554;
int Do = 523;

// define the notes
int half=0;
int dottedHalf=0;
int quarter= 0;
int dottedQuarter=0;
int eighth=0;  
int dottedEighth=0;
int sixteenth=0;
int dotted16th =0;
int bpm= 120;

#include <map>

std::map<int, int> my_map = {
    { '', '1' },
    { 'B', '2' },
    { 'C', '3' }
};

void setup(){
      pinMode(BuzzerPin,OUTPUT);
      
      quarter= 60000/bpm;
      dottedQuarter = quarter*1.5;
      eighth = quarter/2;
      dottedEighth = eighth * 1.5;
      half = 2 * quarter;
      dottedHalf = 3 * quarter;
      sixteenth = eighth / 2;
      dotted16th = 1.5 * sixteenth;

      
}

int Si2 =1975;
int LaS2=1864;
int La2= 1760;
int SolS2=1661;
int Sol2=1567;
int FaS2=1479;
int Fa2= 1396;
int Mi2= 1318;
int ReS2=1244;
int Re2= 1174;
int DoS2=1108;
int Do2= 1046;

// Low Octave
int Si = 987;
int LaS= 932;
int La = 880;
int SolS=830;
int Sol= 783;
int FaS= 739;
int Fa=  698;
int Mi=  659;
int ReS= 622;
int Re = 587;
int DoS =554;
int Do = 523;

void loop(){
  tone(BuzzerPin,Mi,eighth);
  delay(eighth+50);
  tone(BuzzerPin,La,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Si,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Do2,eighth);
  delay(eighth+50);
  tone(BuzzerPin,La,eighth);
  
  delay(2*quarter+50);
  
  tone(BuzzerPin,Mi,eighth);
  delay(eighth+50);
  tone(BuzzerPin,La,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Si,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Do2,eighth);
  delay(eighth+50);
  tone(BuzzerPin,La,eighth);
  
  delay(2*quarter+50);
  
  tone(BuzzerPin,Mi,eighth);
  delay(eighth+50);
  tone(BuzzerPin,La,eighth);  // BELLA
  delay(eighth+50);
  tone(BuzzerPin,Si,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Do2,quarter*1.3);
  delay(2*eighth+50);
  
  tone(BuzzerPin,Si,eighth); // BELLA CIAO
  delay(eighth+50);
  tone(BuzzerPin,La,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Do2,quarter*1.3);
  delay(2*eighth+50);
  
  tone(BuzzerPin,Si,eighth);
  delay(eighth+50);
  tone(BuzzerPin,La,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Mi2,eighth); // CIAO CIAO CIAO
  delay(quarter+50);
  tone(BuzzerPin,Mi2,eighth);
  delay(quarter+100);
  tone(BuzzerPin,Mi2,eighth);
  delay(quarter+50);
  
  tone(BuzzerPin,Re2,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Mi2,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Fa2,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Fa2,quarter*1.3);
  delay(half+100);
  
  tone(BuzzerPin,Fa2,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Mi2,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Re2,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Fa2,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Mi2,quarter*1.3);
  delay(half+100);
  
  tone(BuzzerPin,Mi2,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Re2,eighth);
  delay(eighth+50);
   tone(BuzzerPin,Do2,eighth);
  delay(eighth+50);
  tone(BuzzerPin,Si,quarter*1.3);
  delay(quarter+50);
  tone(BuzzerPin,Mi2,quarter*1.3);
  delay(quarter+50);
  tone(BuzzerPin,Si,quarter*1.3);
  delay(quarter+50);
  tone(BuzzerPin,Do2,quarter*1.3);
  delay(quarter+50);
  tone(BuzzerPin,La,half*1.3);
  delay(half+50);
  
}

int duration(int beat, int bpm) {
   // returns number of milliseconds a given beat length should be
   int result;
   result = beat * 1000 * (60/bpm);
   return result;
}
