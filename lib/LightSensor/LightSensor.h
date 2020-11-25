#ifndef LightSensor_h
#define LightSensor_h

#include "Arduino.h"

class LightSensor
{
private:
    uint8_t _pin;
    float _lightPerc;

public:
    LightSensor(uint8_t pin);
    float getLightPerc();
    void read();
    void setup();
};

#endif