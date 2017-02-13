#ifndef TWINKLE_H
#define TWINKLE_H

#include "TinyTone.h"

// ***
// *** Twinkle, Twinkle Little Star
// ***
const NOTE _notes3[] =  { {C, 4, QUARTER}, {C, 4, QUARTER}, {G, 4, QUARTER}, {G, 4, QUARTER}, {A, 4, QUARTER}, {A, 4, QUARTER}, {G, 4, HALF},
                          {F, 4, QUARTER}, {F, 4, QUARTER}, {E, 4, QUARTER}, {E, 4, QUARTER}, {D, 4, QUARTER}, {D, 4, QUARTER}, {C, 4, HALF},
                          {G, 4, QUARTER}, {G, 4, QUARTER}, {F, 4, QUARTER}, {F, 4, QUARTER}, {E, 4, QUARTER}, {E, 4, QUARTER}, {D, 4, HALF},
                          {G, 4, QUARTER}, {G, 4, QUARTER}, {F, 4, QUARTER}, {F, 4, QUARTER}, {E, 4, QUARTER}, {E, 4, QUARTER}, {D, 4, HALF},
                          {C, 4, QUARTER}, {C, 4, QUARTER}, {G, 4, QUARTER}, {G, 4, QUARTER}, {A, 4, QUARTER}, {A, 4, QUARTER}, {G, 4, HALF},
                          {F, 4, QUARTER}, {F, 4, QUARTER}, {E, 4, QUARTER}, {E, 4, QUARTER}, {D, 4, QUARTER}, {D, 4, QUARTER}, {C, 4, HALF} };

const SONG TwinkleLittleStar = { _notes3, 42, 1000 };
#endif
