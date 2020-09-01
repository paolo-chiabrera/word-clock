#include "Arduino.h"
#include "DHT.h"
#include "SensorHT.h"

void SensorHT::setup()
{
    _dht.begin();
}

float SensorHT::getHumidity() {
    float t = _dht.readHumidity();
    if (isnan(t))
    {
        return -1;
    }

    return t;
}

float SensorHT::getTemperature() {
    float t = _dht.readTemperature();
    if (isnan(t)) {
        return -1;
    }

    return t;
}
