/*
  Snapduino Motion
  This experiment will demonstrate the how to detect motion
  using the Snapduino.

  Daniel Porrey
  https://www.hackster.io/snapcircuits

*/

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
// *** The pin on which the LED is connected.
// ***
#define LED_PIN 4

// ***
// *** The pin on which the LED is connected.
// ***
#define MOTION_PIN 2

// ***
// ***
// ***
int _previousValue = LOW;

void setup()
{
  // ***
  // *** Initialize the Serial port
  // ***
  Serial.begin(115200);
  Serial.println("Initializing...");

  // ***
  // *** Start with the LED at the minimum value.
  // ***
  pinMode(LED_PIN, OUTPUT);

  // ***
  // *** Initialize the pin the whistle chip
  // *** is conecte dot and set the mode to
  // *** input with a pullup resistor.
  // ***
  pinMode(MOTION_PIN, INPUT);

  // ***
  // *** Initialize the previous value variable.
  // ***
  _previousValue = digitalRead(MOTION_PIN);

  // ***
  // *** Report the end ofinitialization
  // *** to the serial port monitor.
  // ***
  Serial.println("Initialization complete.");
}

void loop()
{
  // ***
  // ***
  // ***
  int value = digitalRead(MOTION_PIN);

  // ***
  // ***
  // ***
  if (_previousValue != value)
  {
    if (value == LOW)
    {
      // ***
      // ***
      // ***
      Serial.println("NO Motion Detected.");
      digitalWrite(LED_PIN, LOW);
    }
    else
    {
      // ***
      // ***
      // ***
      Serial.println("Motion Detected!");
      digitalWrite(LED_PIN, HIGH);
    }

    // ***
    // ***
    // ***
    _previousValue = value;
  }

  // ***
  // *** Delay 250 milliseconds.
  // ***
  delay(250);
}
