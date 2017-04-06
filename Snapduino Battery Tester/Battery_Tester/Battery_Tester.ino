/*
  Snapduino Battery Tester
  This experiment will simulate a candle using an LED and
  allow you to blow it out using the whistle chip.

  Daniel Porrey
  https://www.hackster.io/snapcircuits

*/

#include "DualLed.h"
#include "BatteryTester.h"

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
#define BATTERY_PIN 1

// ***
// *** Good battery threshold. Defines the percetage
// *** above which a bettery is considered "good".
// ***
#define BATTERY_THRESHOLD .85

// ***
// *** Create a DualLed instance.
// ***
DualLed _led = DualLed();

// ***
// *** Create a BatteryTester instance.
// ***
BatteryTester _tester = BatteryTester();

// ***
// *** Cache the last known battery voltage.
// ***
float _lastVoltage = 0;

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
  // ***
  // ***
  _tester.begin(BATTERY_PIN, 1000, 100000, 1.51);

  // ***
  // *** Report the end ofinitialization
  // *** to the serial port monitor.
  // ***
  Serial.println("Initialization complete.");
}

void loop()
{
  float volatge = _tester.voltage();
  float charge = _tester.charge();

  // ***
  // *** If the voltage changes more than .1V
  // ** *then check then update the display.
  // ***
  if (abs(_lastVoltage - volatge) > .1)
  {
    // ***
    // *** Store thevalue.
    // ***
    _lastVoltage = volatge;

    // ***
    // *** Set the LED status.
    // ***
    if (charge <= .1)
    {
      Serial.println("Battery removed.");
      _led.off();
    }
    else
    {
      Serial.println("Battery inserted:");

      if (charge >= BATTERY_THRESHOLD)
      {
        _led.green();
        Serial.println("\tBattery is good.");
      }
      else
      {
        Serial.println("Battery inserted:");
        _led.red();
        Serial.println("\tBattery is weak.");
      }

      // ***
      // *** Show the battery voltage and charge.
      // ***
      Serial.print("\tBattery = "); Serial.print(volatge); Serial.print("v ["); Serial.print(100 * charge); Serial.println("%]"); Serial.println();
    }
  }

  // ***
  // *** Short delay.
  // ***
  delay(500);
}
