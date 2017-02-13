#ifndef SHAVE_H
#define SHAVE_H

#include "TinyTone.h"

// ***
// *** Shave and a Haircut
// ***
const NOTE _notes1[] =  { {C, 4, QUARTER}, {G, 3, EIGHTH}, {G, 3, EIGHTH}, {A, 3, QUARTER}, {G, 3, QUARTER}, {REST, 0, QUARTER}, {B, 3, QUARTER}, {C, 4, QUARTER} };

const SONG ShaveAndAHaircut = { _notes1, 8, 1000 };
#endif
