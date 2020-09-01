#include "Arduino.h"
#include "Rotatory.h"

Rotatory::Rotatory(uint8_t pinA, uint8_t pinB)
{
    _pinA = pinA;
    _pinB = pinB;
}

void Rotatory::setup()
{
    pinMode(_pinA, INPUT);
    pinMode(_pinB, INPUT);

    _currentStatePinA = _lastStatePinA = digitalRead(_pinA);
}

void Rotatory::loop(CallbackFunction onNegativeRotation, CallbackFunction onPositiveRotation)
{
    _currentStatePinA = digitalRead(_pinA);

    if (_currentStatePinA != _lastStatePinA)
    {
        if (_currentStatePinA != digitalRead(_pinB))
        {
            // increase
            onNegativeRotation();
        }
        else
        {
            // decrease
            onPositiveRotation();
        }
        _lastStatePinA = _currentStatePinA;
    }
}