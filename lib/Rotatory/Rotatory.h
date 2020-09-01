#ifndef Rotatory_h
#define Rotatory_h_h

#include "Arduino.h"

class Rotatory
{
private:
    uint8_t _pinA;
    uint8_t _pinB;
    int _currentStatePinA;
    int _lastStatePinA;
    typedef void (*CallbackFunction)();

public:
    Rotatory(uint8_t pinA, uint8_t pinB);
    void loop(CallbackFunction onNegativeRotation, CallbackFunction onPositiveRotation);
    void setup();
};

#endif
