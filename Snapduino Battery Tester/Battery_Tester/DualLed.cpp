#include "DualLed.h"

DualLed::DualLed()
{
}

DualLed::begin(uint8_t pin)
{
  this->_pin = pin;
  this->off();
}

void DualLed::green()
{
  // ***
  // *** The Anode of the red
  // *** LED is connected to the pin.
  // ***
  pinMode(this->_pin, OUTPUT);
  digitalWrite(this->_pin, HIGH);
}

void DualLed::red()
{
  // ***
  // *** The Cathode of the red
  // *** LED is connected to the pin.
  // ***
  pinMode(this->_pin, OUTPUT);
  digitalWrite(this->_pin, LOW);
}

void DualLed::off()
{
  // ***
  // *** Place the pin into floating state.
  // ***
  pinMode(this->_pin, INPUT);
}

