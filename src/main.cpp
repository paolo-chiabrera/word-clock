#include "Arduino.h"
#include "arduino-timer.h"
#include "Button2.h"

#include "Clock.h"
// #include "LightSensor.h"
#include "SensorHT.h"
#include "Rotatory.h"
#include "LedMatrix.h"
#include "Menu.h"

// PINS
#define SENSOR_HT_PIN 7
// #define LIGHT_SENSOR_PIN A7
#define ROTATORY_CLOCK_PIN 21 // A
#define ROTATORY_DATA_PIN 20  // B
#define ROTATORY_RESET_PIN 22 // PRESS
#define RTM_CLOCK_PIN 4
#define RTM_DATA_PIN 3
#define RTM_RESET_PIN 2

#define INTERVAL_TIME 5000
#define LEDS_NUMBER 120

auto timer = timer_create_default();
Button2 button = Button2(ROTATORY_RESET_PIN);
Menu menu = Menu();

Clock clock(RTM_DATA_PIN, RTM_CLOCK_PIN, RTM_RESET_PIN);
// LightSensor lightSensor(LIGHT_SENSOR_PIN);
Rotatory rotatory(ROTATORY_CLOCK_PIN, ROTATORY_DATA_PIN);
SensorHT sensorHT(SENSOR_HT_PIN);
LedMatrix ledMatrix(LEDS_NUMBER);

// GLOBALS
// float lightPerc = 0;
float humidity = 0;
float temperature = 0;
uint8_t minutes = 0;
uint8_t hours = 0;
uint8_t intervalsCounter = 0;
bool nightMode = false;
bool changeColour = false;

// HELPERS
void updateIntervalCounter()
{
    intervalsCounter++;

    if (intervalsCounter > 10)
    {
        intervalsCounter = 0;
    }
}

bool onTimerInterval(void *)
{
    changeColour = hours != clock.getHours() || minutes != clock.getMinutes();

    // lightPerc = lightSensor.getLightPerc();
    humidity = sensorHT.getHumidity();
    temperature = sensorHT.getTemperature();
    minutes = clock.getMinutes();
    hours = clock.getHours();
    nightMode = hours >= 0 && hours < 8;

    ledMatrix.setLowLight(nightMode);

    if (intervalsCounter % 20 == 0)
    {
        ledMatrix.showHumidity(humidity);
    }
    else if (intervalsCounter % 10 == 0)
    {
        ledMatrix.showTemperature(temperature);
    }
    else
    {
        ledMatrix.update(minutes, hours, changeColour);
    }

    updateIntervalCounter();

    return true;
}

void onNegativeRotation()
{
    menu.onBackScrolling();
}

void onPositiveRotation()
{
    menu.onForwardScrolling();
}

void menuCallback(uint8_t value)
{
    Serial.println(value, DEC);
}

void clickHandler(Button2 &btn)
{
    switch (btn.getClickType())
    {
    case SINGLE_CLICK:
    case LONG_CLICK:
        Serial.println("SINGLE");
        menu.onConfirm(MAX_MINUTES_VALUE);
        break;
    case DOUBLE_CLICK:
    case TRIPLE_CLICK:
        Serial.println("Double/Triple");
        menu.onCancel();
        break;
    }
}

//  SETUP

void setup()
{
    Serial.begin(9600);

    clock.setup();
    // lightSensor.setup();
    rotatory.setup();
    sensorHT.setup(0, -4);
    ledMatrix.setup();

    menu.setCallback(&menuCallback);

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