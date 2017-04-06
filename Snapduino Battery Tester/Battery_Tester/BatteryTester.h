#ifndef BATTERY_TESTER_H
#define BATTERY_TESTER_H

#include "Arduino.h"

class BatteryTester
{
  public:
    BatteryTester();
    void begin(uint8_t analogPin, uint16_t r1, uint16_t r2, float maxVolatge);
    float voltage();
    float charge();

  private:
    uint16_t _r1 = 0;
    uint16_t _r2 = 0;
    uint8_t _analogPin = 0;
    float _maxVoltage = 0;
};
#endif
