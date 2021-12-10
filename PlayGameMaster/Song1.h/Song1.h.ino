
  const int toxicButtons[] = {0, -1, 0, -1, 3, 2, 0, 2, 3, -1, -1, 0, 3, 2, 0, -1, 2, -1, -1, -1, 2, -1
  , -1, -1, 3, -1, 2, -1, 0, -1, -1, -1, 0, -1, 0, -1, 3, 2, 0, 2, 3,
  -1, -1, 0, 3, 2, 0, -1, 2, -1, -1, -1, 2, -1, -1, -1, 3, -1, 2, -1,
  0, -1, -1, -1, 0, -1, 0, -1, 3, 2, 0, 2, 3, -1, -1, 0, 3, 2, 0, -1, 2, -1,
  -1, -1, 2, -1, -1, -1, 3, -1, 2, -1, 0, -1, -1, -1, 0, -1, 0, -1, 3, 2, 0, 2, 
  3, -1, -1, 0, 3, 2, 0, -1, 2, -1, -1, -1, 2, -1, -1, -1, 3, -1, 2, -1, 0, -1, -1,
  -1, -1, -1, -1, -1, -1, 0, -1, 2, -1, 3, -1, 2, -1, 0, -1, -1, -1, 
  -1, -1, -1, -1, -1, -1, 0, -1, 3, -1, 0, -1, 3, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, 0, -1, 3, -1, 2, -1, 0, -1, -1, -1, -1, -1, 0, -1, 
  0, -1, 0, -1, 3, -1, 0, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  2, -1, 2, -1, 0, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3, -1,
  3, -1, 3, -1, 3, -1, -1, -1, 0, -1, 0, -1, 3, 2, 0, 2, 3, -1, -1, 0,
  3, 2, 0, -1, 2, -1, -1, -1, 2, -1, -1, -1, 3, -1, 2, -1, 0, -1, -1,
  -1, -1, -1, -1, -1, -1, 0, -1, 2, -1, 3, -1, 2, -1, 0, -1, -1, -1, 
  -1, -1, -1, -1, -1, -1, 0, -1, 3, -1, 0, -1, 3, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, 0, -1, 3, -1, 2, -1, 0, -1, -1, -1, -1, -1, 0, -1, 0, -1, 0, -1,
  3, -1, 0, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, -1, 2, -1, 0, -1, 2, -1, -1, -1, -1, -1, -1, -1, 
  -1, -1, 3, -1, 3, -1, 3, -1, 3, -1, -1, -1, 0, -1, 0, -1, 3, 2, 0, 2, 3, -1, -1, 0, 3, 2, 0, -1, 2, -1, -1, 
  -1, 2, -1, -1, -1, 3, -1, 2, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1,
  2, -1, -1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 3, -1, -1, -1, -1, -1, 3, -1, 3, -1, 3, -1, 1, -1, -1, -1, 1, -1, 1, -1, 2, -1, -1, -1,
  1, -1, -1, -1, 1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, 3, -1,
  2, -1, 3, -1, 1, -1, -1, -1, 0, -1, 0, -1, 3, 2, 0, 2, 3, -1, -1, 0, 3, 2, 0, -1, 2, -1, -1, -1, 2, -1, -1, -1, 3, -1, 2, -1, 0, -1, -1, -1, 0, -1, 0, -1, 0, -1, 0, 
  -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, 3, -1, 2, -1, 2, -1, -1, -1, 0, -1, 2, -1, 2, -1, -1, -1, 3, -1, -1, -1, 1, -1, 3, -1, 2, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, 3, -1, -1, -1, 0, -1, -1, -1, 3, -1, -1, -1, 0, -1, 0, -1, 3, -1, -1, -1, 3, -1, 2, -1, 2, -1, -1, -1, 0, -1, 
  2, -1, 2, -1, -1, -1, 3, -1, -1, -1, 1, -1, 3, -1, 2, -1, -1, -1, -1, -1, -1, -1, 0, -1, 3, -1, 2, -1, -1, -1, 1, -1, 3, -1, 3, -1, -1, -1, 0, -1, 3, -1, 2, -1, -1, -1, 1, -1, 3, -1, 1, -1, -1,
  -1, 3, -1, -1, -1, 3, -1, -1, -1};


const int sizeOfToxic = 260;
const int bpm = 72;

const int Toxic[sizeOfToxic][3] = {
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
