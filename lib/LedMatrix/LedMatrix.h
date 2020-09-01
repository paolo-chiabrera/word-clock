#ifndef LedMatrix_h
#define LedMatrix_h

#include "Arduino.h"
#include "FastLED.h"

#define COLOR_ORDER GRB
#define CHIPSET WS2812B
#define LED_MATRIX_PIN 15

class LedMatrix
{
private:
    CRGB *_leds = NULL;
    uint8_t _ledsNumber;

public:
    LedMatrix(uint8_t ledsNumber = 120);
    void setup();
    bool isNextHour(int minutes = 0);
    void testLights(CRGB colour = CRGB::White);
};

#endif