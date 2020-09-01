#ifndef LightSensor_h
#define LightSensor_h

#include "Arduino.h"

class LightSensor
{
private:
    uint8_t _pin;
    bool _isLowLight;

public:
    LightSensor(uint8_t pin);
    bool isLowLight();
    void read();
    void setup();
};

#endif