#include "BatteryTester.h"

BatteryTester::BatteryTester()
{
}

void BatteryTester::begin(uint8_t analogPin, uint16_t r1, uint16_t r2, float maxVoltage)
{
  // ***
  // *** Store these values:
  // ***
  // *** r1: Resistor value 1 in the voltage divider
  // *** r2: Resistor value 2 in the voltage divider (this is one we measure)
  // *** analogPin: The pin used to measure the voltage.
  // *** maxVoltage: The maximum voltage of the battery (we are testing AA batteries)
  // ***
  this->_r1 = r1;
  this->_r2 = r2;
  this->_analogPin = analogPin;
  this->_maxVoltage = maxVoltage;
}

float BatteryTester::voltage()
{
  // ***
  // *** Mease the voltage on the analog port. This will return
  // *** a number between 0 and 1023.
  // ***
  uint16_t value = analogRead(this->_analogPin);

  // ***
  // *** Calculate the volatage across R2 by dividing
  // *** the value read from the analog port by the 
  // *** maximum value (1023) and multiplying it by
  // *** the maximum volatge of 3.3V.
  // ***
  float measuredVoltage = (float)value / 1023.0 * 3.3;

  // ***
  // *** Using the voltage divider equation (see https://learn.sparkfun.com/tutorials/voltage-dividers)
  // *** calculate the voltage Vin which is the battery voltage.
  // ***
  return measuredVoltage / ((float)this->_r2 / ((float)this->_r1 + (float)this->_r2));
}

float BatteryTester::charge()
{
  float returnValue = 0;

  // ***
  // *** Calculate the battery percentage by taking the
  // *** battery voltage and dividing by the maximum
  // *** expcted battery voltage.
  // ***
  returnValue = this->voltage() / this->_maxVoltage;

  // ***
  // *** DOn;t let the percentage go above 1.
  // ***
  if (returnValue > 1.0) returnValue = 1.0;

  return returnValue;
}
