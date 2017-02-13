#ifndef TINY_TONE_H
#define TINY_TONE_H

const double TwelfthRootOfTwo = 1.0594630943592952645;
const double BaseFrequency = 16.35;

// *************************************************
// *** Public Constants
// *************************************************
#define WHOLE      1
#define HALF       2
#define DOTHALF    2
#define QUARTER    4
#define DOTQUARTER 6
#define EIGHTH     8
#define DOTEIGHTH 12
#define SIXTEENTH 16

#define REST 0
#define C    1
#define CS   2
#define D    3
#define DS   4
#define E    5
#define F    6
#define FS   7
#define G    8
#define GS   9
#define A   10
#define AS  11
#define BF  11
#define B   12

const char _names[] = { 'R', 'C', 'C', 'D', 'D', 'E', 'F', 'F', 'G', 'G', 'A', 'A', 'B' };

struct NOTE
{
  uint8_t scale;
  uint8_t octave;
  uint16_t duration;
};

struct SONG
{
  NOTE* notes;
  uint16_t noteCount;
  uint16_t tempo;
};

// ***
// *** Takes a note on the scale from 1 to 12 and the
// *** desired octave and calcuates the frequeny.
// ***
double noteFrequency(NOTE note)
{
  double returnValue = 0.0;

  // ***
  // *** Make sure the octave is 0 to 8 and scale is 1 to 12.
  // ***
  if ((note.octave >= 0 && note.octave < 9) && (note.scale > 0 && note.scale < 13))
  {
    returnValue = BaseFrequency;

    uint8_t multiplier = (12 * note.octave - 1) + note.scale;

    for (int i = 0; i < multiplier; i++)
    {
      returnValue *= TwelfthRootOfTwo;
    }
  }

  return returnValue;
}

String noteName(NOTE note)
{
  char buffer[5];

  if (note.scale == 0)
  {
    sprintf(buffer, "Rest", _names[note.scale], note.octave);
  }
  else if (note.scale == 2 || note.scale == 4 || note.scale == 7 || note.scale == 9 || note.scale == 11 )
  {
    sprintf(buffer, "%c#-%d", _names[note.scale], note.octave);
  }
  else
  {
    sprintf(buffer, "%c -%d", _names[note.scale], note.octave);
  }

  return String(buffer);
}

volatile uint32_t toggle_count;

void TinyTone(uint16_t frequency, uint32_t duration)
{
  // ***
  // *** Scan through prescalars to find the best fit.
  // ***
  uint32_t ocr = F_CPU / frequency / 2;
  uint8_t prescalarBits = 1;

  while (ocr > 255)
  {
    prescalarBits++;
    ocr /= 2;
  }

  // ***
  // *** CTC mode; toggle OC1A pin; set prescalar.
  // ***
  TCCR1 = 0x90 | prescalarBits;

  // ***
  // *** Calculate note duration in terms of toggle count
  // *** Duration will be tracked by timer1 ISR
  // ***
  toggle_count = frequency * duration / 500;
  OCR1C = ocr - 1; // Set the OCR
  bitWrite(TIMSK, OCIE1A, 1); // enable interrupt
}

// ***
// *** Timer1 Interrupt Service Routine. Keeps
// *** track of note duration via toggle counter.
// *** When correct time has elapsed, counter is
// *** disabled.
// ***
ISR(TIMER1_COMPA_vect)
{
  if (toggle_count != 0)
  {
    // ***
    // *** Done yet?, no, keep counting.
    // ***
    toggle_count--;
  }
  else
  {
    // ***
    // *** Yes, stop the counter
    // ***
    TCCR1 = 0x90;
  }
}

void playMelody(NOTE* melody, uint16_t noteCount, uint16_t tempo)
{
  for (int i = 0; i < noteCount; i++)
  {
    uint16_t frequency = (uint16_t)noteFrequency(melody[i]);
    uint16_t noteDuration = tempo / melody[i].duration;

    // ***
    // *** Watch for rests with a frequency of 0.
    // ***
    if (frequency != 0)
    {
      // ***
      // *** Play the note.
      // ***
      TinyTone(frequency, noteDuration);
    }

    // ***
    // *** Need to wait for the note finish playing.
    // ***
    int delayAfter = noteDuration * 1.3;
    delay(delayAfter);
  }
}
#endif
