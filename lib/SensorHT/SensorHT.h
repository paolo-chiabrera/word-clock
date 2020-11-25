#ifndef SensorHT_h
#define SensorHT_h

#include "Arduino.h"
#include "DHT.h"

class SensorHT
{
private:
    DHT *_dht;
    uint8_t _humidityDelta;
    uint8_t _temperatureDelta;

public:
    SensorHT(uint8_t pin, uint8_t type = DHT11);
    void setup(uint8_t humidityDelta = 0, uint8_t temperatureDelta = 0);
    uint8_t getHumidity();
    uint8_t getTemperature();
};

#endif
