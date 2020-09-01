#include "Arduino.h"
#include "arduino-timer.h"
#include "Button2.h"

#include "LightSensor.h"
#include "SensorHT.h"
#include "Rotatory.h"

// PINS
#define SENSOR_HT_PIN 7
#define LIGHT_SENSOR_PIN 11
#define ROTATORY_PIN_A 21      // CLOCK
#define ROTATORY_PIN_B 20      // DATA
#define ROTATORY_PIN_BUTTON 22 // RESET

#define INTERVAL_TIME 5000

auto timer = timer_create_default();
Button2 button = Button2(ROTATORY_PIN_BUTTON);

LightSensor lightSensor(LIGHT_SENSOR_PIN);
Rotatory rotatory(ROTATORY_PIN_A, ROTATORY_PIN_B);
SensorHT sensorHT(SENSOR_HT_PIN);

// GLOBALS
boolean isLowLight = false;
float humidity = 0;
float temperature = 0;

// HELPERS
bool onTimerInterval(void *)
{
    humidity = sensorHT.getHumidity();
    isLowLight = lightSensor.isLowLight();
    temperature = sensorHT.getTemperature();

    return true;
}

void onNegativeRotation()
{
    Serial.println("NEG");
}

void onPositiveRotation()
{
    Serial.println("POS");
}

void clickHandler(Button2 &btn)
{
    switch (btn.getClickType())
    {
    case SINGLE_CLICK:
    case LONG_CLICK:
        Serial.println("SINGLE");
        // onSingleClick();
        break;
    case DOUBLE_CLICK:
    case TRIPLE_CLICK:
        Serial.println("Double/Triple");
        // onDoubleClick();
        break;
    }
}

//  SETUP

void setup()
{
    Serial.begin(9600);

    lightSensor.setup();
    rotatory.setup();
    sensorHT.setup();

    // Button
    button.setClickHandler(clickHandler);
    button.setDoubleClickHandler(clickHandler);
    button.setTripleClickHandler(clickHandler);
    button.setLongClickHandler(clickHandler);

    onTimerInterval(NULL);

    timer.every(INTERVAL_TIME, onTimerInterval);
}

void loop()
{
    button.loop();
    rotatory.loop(onNegativeRotation, onPositiveRotation);
    timer.tick();
}