/*
  Breathing LED
  Change the apparent brightness of an LED.

  Daniel Porrey
  Snap Circuits - Breathing LED
  https://www.hackster.io/porrey/sc-breathingled

*/

// ***
// *** Specifies the pin on which the LED is connected.
// ***
#define LED_PIN 2

// ***
// *** Parameters for "breathing"
// ***
#define MINIMUM_ANALOG 0
#define MAXIMUM_ANALOG 220
#define STEP 1
#define DELAY 7

// ***
// *** The setup function runs once when you press
// *** reset or power the board.
// ***
void setup()
{
  // ***
  // *** Initialize the digital pin for output.
  // ***
  pinMode(LED_PIN, OUTPUT);
}

// ***
// *** The loop function runs over
// *** and over again forever.
// ***
void loop()
{
  for (int i = MINIMUM_ANALOG; i <= MAXIMUM_ANALOG; i += STEP)
  {
    analogWrite(LED_PIN, i);
    delay(DELAY);
  }

  for (int i = MAXIMUM_ANALOG; i >= MINIMUM_ANALOG; i -= STEP)
  {
    analogWrite(LED_PIN, i);
    delay(DELAY);
  }
}
