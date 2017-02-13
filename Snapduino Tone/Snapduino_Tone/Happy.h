#ifndef HAPPY_H
#define HAPPY_H

#include "TinyTone.h"

// ***
// *** Happy Birthday
// ***
const NOTE _notes2[] =  { {C, 4, DOTEIGHTH}, {C, 4, SIXTEENTH}, {D, 4, QUARTER}, {C, 4, QUARTER}, {F, 4, QUARTER}, {E, 4, HALF},
                          {C, 4, DOTEIGHTH}, {C, 4, SIXTEENTH}, {D, 4, QUARTER}, {C, 4, QUARTER}, {G, 4, QUARTER}, {F, 4, HALF},
                          {C, 4, DOTEIGHTH}, {C, 4, SIXTEENTH}, {C, 5, QUARTER}, {A, 4, QUARTER}, {F, 4, QUARTER}, {E, 4, QUARTER}, {D, 4, DOTHALF},
                          {BF, 4, DOTEIGHTH}, {BF, 4, SIXTEENTH}, {A, 4, QUARTER}, {F, 4, QUARTER}, {G, 4, QUARTER}, {F, 4, DOTHALF} };
                          
const SONG HappyBirthday = { _notes2, 25, 1500 };
#endif
