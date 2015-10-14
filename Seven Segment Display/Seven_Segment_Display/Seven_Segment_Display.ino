/*
  Seven Segment Display
  Display numeric digits on a seven segment LED display.

  Daniel Porrey
  Snap Circuits - Seven Segment Display
  https://www.hackster.io/porrey/sc-sevensegmentdisplay
  
*/

// ***
// *** Specifies the amount of time (in milliseconds)
// *** to pause between truning the LED's on and off.
// ***
#define DELAY 1000

// ***
// *** The pins used for each LED segment. The
// *** seven segment display has it's segments 
// *** label A through G and DP for the period.
// ***
#define PIN_A  1
#define PIN_B  2
#define PIN_C  3
#define PIN_D  4
#define PIN_E  5
#define PIN_F  6
#define PIN_G  7
#define PIN_DP 8

// ***
// *** Specifies the index of each pin 
// *** in the FONT array.
// ***
#define IDX_A  0
#define IDX_B  1
#define IDX_C  2
#define IDX_D  3
#define IDX_E  4
#define IDX_F  5
#define IDX_G  6
#define IDX_DP 7

// ***
// *** Defines the charcaters by specifying
// *** which segment is HIGH or lOW for the
// *** specific character.
// ***
#define CHARACTER_COUNT 23
const uint8_t FONT[CHARACTER_COUNT][8] =
{
//   A     B     C     D     E     F     G     DP      Character  Index
    {LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  HIGH, HIGH }, // Zero    [ 0]
    {HIGH, LOW,  LOW,  HIGH, HIGH, HIGH, HIGH, HIGH }, // One     [ 1]
    {LOW,  LOW,  HIGH, LOW,  LOW,  HIGH, LOW,  HIGH }, // Two     [ 2]
    {LOW,  LOW,  LOW,  LOW,  HIGH, HIGH, LOW,  HIGH }, // Three   [ 3]
    {HIGH, LOW,  LOW,  HIGH, HIGH, LOW,  LOW,  HIGH }, // Four    [ 4]
    {LOW,  HIGH, LOW,  LOW,  HIGH, LOW,  LOW,  HIGH }, // Five    [ 5]
    {HIGH, HIGH, LOW,  LOW,  LOW,  LOW,  LOW,  HIGH }, // Six     [ 6]
    {LOW,  LOW,  LOW,  HIGH, HIGH, HIGH, HIGH, HIGH }, // Seven   [ 7]
    {LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  HIGH }, // Eight   [ 8]
    {LOW,  LOW,  LOW,  HIGH, HIGH, LOW,  LOW,  HIGH }, // Nine    [ 9]    
    {LOW,  LOW,  LOW,  HIGH, LOW,  LOW,  LOW,  HIGH }, // A       [10]
    {LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  HIGH }, // B       [11]
    {LOW,  HIGH, HIGH, LOW,  LOW,  LOW,  HIGH, HIGH }, // C       [12]
    {LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  HIGH, HIGH }, // D       [13]
    {LOW,  HIGH, HIGH, LOW,  LOW,  LOW,  LOW,  HIGH }, // E       [14]
    {LOW,  HIGH, HIGH, HIGH, LOW,  LOW,  LOW,  HIGH }, // F       [15]
    {LOW,  HIGH, LOW,  LOW,  LOW,  LOW,  LOW,  HIGH }, // G       [16]
    {HIGH, LOW,  LOW,  HIGH, LOW,  LOW,  LOW,  HIGH }, // H       [17]
    {HIGH, LOW,  LOW,  HIGH, HIGH, HIGH, HIGH, HIGH }, // I       [18]
    {HIGH, LOW,  LOW,  LOW,  HIGH, HIGH, HIGH, HIGH }, // J       [19]
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW  }, // Period  [20]
    {LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW  }, // All On  [21]
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH }  // All Off [22]
};

// ***
// *** Index of special characers
// *** in the FONT array
// ***
#define ALL_ON 21
#define ALL_OFF 22

// ***
// *** The setup function runs once when you press
// *** reset or power the board.
// ***
void setup()
{
  // ***
  // *** Set all pins to output mode
  // ***
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_DP, OUTPUT);
  
  // ***
  // *** LED Test: Turn all LED's
  // *** on and then off.
  // ***
  DisplayCharacter(ALL_ON);
  delay(DELAY);
  delay(DELAY);  
  DisplayCharacter(ALL_OFF);
  delay(DELAY);
  delay(DELAY);
}

// ***
// *** The loop function runs over 
// *** and over again forever.
// ***
void loop()
{
  // ***
  // *** Display each character 
  // *** in the FONT array
  // ***
  for(int i = 0; i < CHARACTER_COUNT; ++i)
  {    
    DisplayCharacter(i);
    delay(DELAY);
  }
}

void DisplayCharacter(int charIndex)
{
  // ***
  // *** Set each pin according to the FONT
  // *** definition.
  // ***
  digitalWrite(PIN_A,  FONT[charIndex][IDX_A]);
  digitalWrite(PIN_B,  FONT[charIndex][IDX_B]);
  digitalWrite(PIN_C,  FONT[charIndex][IDX_C]);
  digitalWrite(PIN_D,  FONT[charIndex][IDX_D]);
  digitalWrite(PIN_E,  FONT[charIndex][IDX_E]);
  digitalWrite(PIN_F,  FONT[charIndex][IDX_F]);
  digitalWrite(PIN_G,  FONT[charIndex][IDX_G]);
  digitalWrite(PIN_DP, FONT[charIndex][IDX_DP]);
}
