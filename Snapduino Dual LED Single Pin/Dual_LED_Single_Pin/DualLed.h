#ifndef DUAL_LED_H
#define DUAL_LED_H

#include "Arduino.h"

class DualLed
{
  public:
    DualLed();
    begin(uint8_t pin);
    void off();
    void green();
    void red();

  private:
    uint8_t _pin = 0;
};
#endif
