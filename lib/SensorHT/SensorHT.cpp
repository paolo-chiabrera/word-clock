#include "Arduino.h"
#include "DHT.h"
#include "SensorHT.h"
#include "math.h"

SensorHT::SensorHT(uint8_t pin, uint8_t type)
{
    _dht = new DHT(pin, type);
    _humidityDelta = 0;
    _temperatureDelta = 0;
}

void SensorHT::setup(uint8_t humidityDelta, uint8_t temperatureDelta)
{
    _dht->begin();
    _humidityDelta = humidityDelta;
    _temperatureDelta = temperatureDelta;
}

uint8_t SensorHT::getHumidity()
{
    float t = _dht->readHumidity();
    if (isnan(t))
    {
        return -1;
    }

    return floor(t) + _humidityDelta;
}

uint8_t SensorHT::getTemperature()
{
    float t = _dht->readTemperature();
    if (isnan(t))
    {
        return -1;
    }

    return floor(t) + _temperatureDelta;
}
