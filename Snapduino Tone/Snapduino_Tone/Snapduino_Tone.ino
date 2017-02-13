/*
  Snapduino Motion
  This experiment will demonstrate the how to detect motion
  using the Snapduino.

  Daniel Porrey
  https://www.hackster.io/snapcircuits

*/
#include "TinyTone.h"

// ***
// *** Incude the songs to play. Caution, adding too many may 
// *** cause the ATtiny85 to run out of memory. Watch when it 
// *** compiles - it has 500 bytes of program memory.
// ***
#include "Happy.h"      // HappyBirthday
#include "Shave.h"      // ShaveAndAHaircut
#include "Twinkle.h"    // TwinkleLittleStar
//#include "KnowIt.h"   // HappyAndYouKnowIt

#define SPEAKER_PIN 1

// ***
// *** Select the songs to play by adding them to this list.
// ***
SONG _songs[] = { ShaveAndAHaircut, HappyBirthday, TwinkleLittleStar };

void setup()
{
  // ***
  // ***
  // ***
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop()
{
  // ***
  // *** Play each of the selected songs one at a time.
  // ***
  for (int i = 0; i < sizeof(_songs) / sizeof(SONG); i++)
  {
    playMelody(_songs[i].notes, _songs[i].noteCount, _songs[i].tempo);
    delay(1000);
  }
}
