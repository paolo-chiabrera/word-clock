#ifndef Clock_h
#define Clock_h

#include "Arduino.h"
#include "ThreeWire.h"
#include "RtcDS1302.h"

class Clock
{
private:
    ThreeWire *_myWire;
    RtcDS1302<ThreeWire> *_rtc;
    uint8_t _hours;
    uint8_t _minutes;
    void checkClockSetup(RtcDateTime compiled);
    void updateTimeFromRTC();

public:
    Clock(uint8_t dataPin, uint8_t clockPin, uint8_t resetPin);
    uint8_t getHours();
    uint8_t getMinutes();
    void loop();
    void setup();
};

#endif