/*
  Snapduino Dual LED Single Pin
  Daniel Porrey
  https://www.hackster.io/snapcircuits

*/

#include "DualLed.h"

// ***
// *** The ATtiny85 does not have a built in serial device. To
// *** communicate with the computer over the FTDI cable we need
// *** a serial port emulator.
// ***
#include <SoftwareSerial.h>

// ***
// *** Define the RX and TX pins. Since we already have the FTDI
// *** cable attached for programing, let's use the same pins!
// ***
#define TX    YELLOW_PIN    // *** PB0, D0, ATtiny85 pin 5, Yellow Cable
#define RX    WHITE_PIN     // *** PB1, D1, ATtiny85 pin 6, White Cable

// ***
// *** Define the software based serial port. Using the
// *** name Serial so that code can be used on other
// *** platforms that support hardware based serial. On
// *** chips that support the hardware serial, just
// *** comment this line.
// ***
SoftwareSerial Serial(RX, TX);

// ***
// *** Define the pins used.
// ***
#define LED_PIN 4

// ***
// *** Create a DualLed instance.
// ***
DualLed _led = DualLed();

void setup()
{
  // ***
  // *** Initialize the Serial port
  // ***
  Serial.begin(115200);
  Serial.println("Initializing...");

  // ***
  // *** Initialize the LEDs. The will both initally be off.
  // ***
  _led.begin(LED_PIN);

  // ***
  // *** Report the end ofinitialization
  // *** to the serial port monitor.
  // ***
  Serial.println("Initialization complete.");
}

void loop()
{
  // ***
  // *** Turn the Green LED on.
  // ***
  _led.green();
  delay(1000);

  // ***
  // *** Turn the Red LED on.
  // ***
  _led.red();
  delay(1000);

  // ***
  // *** Turn the both LEDs off.
  // ***
  _led.off();
  delay(1000);
}
