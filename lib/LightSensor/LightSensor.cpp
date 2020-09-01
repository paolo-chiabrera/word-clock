#include "Arduino.h"
#include "LightSensor.h"

LightSensor::LightSensor(uint8_t pin)
{
    _isLowLight = false;
    _pin = pin;
}

void LightSensor::read()
{
    int cumulativeRead = 0;

    cumulativeRead += digitalRead(_pin);
    delay(50);
    cumulativeRead += digitalRead(_pin);
    delay(50);
    cumulativeRead += digitalRead(_pin);
    delay(50);
    cumulativeRead += digitalRead(_pin);
    delay(50);
    cumulativeRead += digitalRead(_pin);

    _isLowLight = boolean(cumulativeRead > 2);
}

void LightSensor::setup()
{
    pinMode(_pin, INPUT);
}

boolean LightSensor::isLowLight()
{
    return _isLowLight;
}
