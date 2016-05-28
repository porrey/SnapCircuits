/*
  Snapduino Basics
  This experiment will demonstrate the basic operation of 
  the Snapduino by blinking the LED D1.

  Daniel Porrey
  https://www.hackster.io/snapcircuits

*/

// ***
// *** Specify the pin on which the LED is connected.
// ***
#define LED_PIN 4

void setup()
{
  // ***
  // *** Set the mode of the LED_PIN
  // *** to output.
  // ***
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // ***
  // *** Turn the LED on.
  // ***
  digitalWrite(4, LOW);

  // ***
  // *** Wait one second.
  // ***
  delay(1000);

  // ***
  // *** Turn the LED off.
  // ***
  digitalWrite(4, HIGH);

  // ***
  // *** Wait one second.
  // ***
  delay(1000);
}
