#ifndef SensorHT_h
#define SensorHT_h

#include "Arduino.h"
#include "DHT.h"

class SensorHT {
    private:
        DHT _dht;
    public:
        SensorHT(uint8_t pin, uint8_t type = DHT11): _dht(pin, type) {};
        void begin();
        float getHumidity();
        float getTemperature();
};

#endif
