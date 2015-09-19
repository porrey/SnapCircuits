/*
  Blinking LED
  Turns the Snap Circuit LED on and off repeatedly.

  Daniel Porrey
  Snap Circuits IoT - Project 1
  https://www.hackster.io/porrey/snapcircuits-prj1
  
*/

// ***
// *** Specifies the pin on which the LED is connected.
// ***
#define LED_PIN 2

// ***
// *** Specifies the amount of time (in milliseconds)
// *** to pause between truning the LED on and off.
// ***
#define DELAY_TIME 1000

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
  // ***
  // *** Turn the LED ON. Since we have connected
  // *** the LED to the 3.3v pin we must set our
  // *** GPIO pin to LOW to light the LED.
  // ***
  digitalWrite(LED_PIN, LOW);
  
  // ***
  // *** Pause
  // ***
  delay(DELAY_TIME);
  
  // ***
  // *** Turn the LED off. Since we have connected
  // *** the LED to the 3.3v pin we must set our
  // *** GPIO pin to HIGH to turn the LED off.
  // ***
  digitalWrite(LED_PIN, HIGH);
  
  // ***
  // *** Pause
  // ***
  delay(DELAY_TIME);
}
