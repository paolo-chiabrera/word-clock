#ifndef LightSensor_h
#define LightSensor_h

#include "Arduino.h"

class LightSensor
{
private:
    uint8_t _pin;
    boolean _isLowLight;

public:
    LightSensor(uint8_t pin);
    boolean isLowLight();
    void read();
    void setup();
};

#endif