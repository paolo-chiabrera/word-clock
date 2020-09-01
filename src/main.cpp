#include "Arduino.h"
#include "arduino-timer.h"
#include "Button2.h"

#include "Clock.h"
#include "LightSensor.h"
#include "SensorHT.h"
#include "Rotatory.h"
#include "LedMatrix.h"

// PINS
#define SENSOR_HT_PIN 7
#define LIGHT_SENSOR_PIN 11
#define ROTATORY_CLOCK_PIN 21 // A
#define ROTATORY_DATA_PIN 20  // B
#define ROTATORY_RESET_PIN 22 // PRESS
#define RTM_CLOCK_PIN 4
#define RTM_DATA_PIN 3
#define RTM_RESET_PIN 2

#define INTERVAL_TIME 5000
#define LEDS_NUMBER 5000

auto timer = timer_create_default();
Button2 button = Button2(ROTATORY_RESET_PIN);

Clock clock(RTM_DATA_PIN, RTM_CLOCK_PIN, RTM_RESET_PIN);
LightSensor lightSensor(LIGHT_SENSOR_PIN);
Rotatory rotatory(ROTATORY_CLOCK_PIN, ROTATORY_DATA_PIN);
SensorHT sensorHT(SENSOR_HT_PIN);
LedMatrix ledMatrix(LEDS_NUMBER);

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

    clock.setup();
    lightSensor.setup();
    rotatory.setup();
    sensorHT.setup();
    ledMatrix.setup();

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
    clock.loop();
    rotatory.loop(onNegativeRotation, onPositiveRotation);
    timer.tick();
}