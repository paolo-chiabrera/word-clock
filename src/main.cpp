#include "Arduino.h"

#include "SensorHT.h"

#define DHTPIN 7

SensorHT sensorHT(DHTPIN);

void setup()
{
    Serial.begin(9600);
    Serial.println("DHTxx test!");

    sensorHT.begin();
}

void loop()
{
    delay(2000);
    float h = sensorHT.getHumidity();
    float t = sensorHT.getTemperature();

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print("\n");
}