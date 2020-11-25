#include "Arduino.h"
#include "LightSensor.h"

LightSensor::LightSensor(uint8_t pin)
{
    _lightPerc = 0;
    _pin = pin;
}

void LightSensor::read()
{
    double cumulativeRead = 0;

    cumulativeRead += analogRead(_pin);
    delay(50);
    cumulativeRead += analogRead(_pin);
    delay(50);
    cumulativeRead += analogRead(_pin);
    delay(50);
    cumulativeRead += analogRead(_pin);
    delay(50);
    cumulativeRead += analogRead(_pin);

    float average = cumulativeRead / 5.0;
    float perc = average / 10.0;
    float fixedPerc = round(perc * 10.0) / 10.0;

    _lightPerc = fixedPerc > 1.0 ? 1.0 : fixedPerc;
}

void LightSensor::setup()
{
    pinMode(_pin, INPUT);
    read();
}

float LightSensor::getLightPerc()
{
    read();
    return _lightPerc;
}
