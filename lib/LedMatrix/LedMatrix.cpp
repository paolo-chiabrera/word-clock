#include "Arduino.h"
#include "FastLED.h"

#include "LedMatrix.h"

LedMatrix::LedMatrix(uint8_t ledsNumber)
{
    _ledsNumber = ledsNumber;
    _leds = new CRGB[ledsNumber];
}

void LedMatrix::testLights(CRGB colour)
{
    for (int i = 0; i < _ledsNumber; i++)
    {
        _leds[i] = colour;
    }

    FastLED.show();
}

bool LedMatrix::isNextHour(int minutes)
{
    return minutes >= 35;
}

void LedMatrix::setup()
{
    FastLED.addLeds<CHIPSET, LED_MATRIX_PIN, COLOR_ORDER>(_leds, _ledsNumber);
    FastLED.setBrightness(50);
    testLights(CRGB::White);
    delay(1000);
    testLights(CRGB::Black);
}