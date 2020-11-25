#include "Arduino.h"
#include "ThreeWire.h"
#include "RtcDS1302.h"

#include "Clock.h"

Clock::Clock(uint8_t dataPin, uint8_t clockPin, uint8_t resetPin)
{
    _myWire = new ThreeWire(dataPin, clockPin, resetPin);
    _rtc = new RtcDS1302<ThreeWire>(*_myWire);
    _hours = 0;
    _minutes = 0;
}

uint8_t Clock::getHours()
{
    return _hours;
}

uint8_t Clock::getMinutes()
{
    return _minutes;
}

void Clock::checkClockSetup(RtcDateTime compiled)
{
    _rtc->SetDateTime(compiled);
    Serial.println("RTC updated with compile time!");

    if (_rtc->GetIsWriteProtected())
    {
        Serial.println("RTC was write protected, enabling writing now");
        _rtc->SetIsWriteProtected(false);
    }

    if (!_rtc->GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        _rtc->SetIsRunning(true);
    }
}

void Clock::updateTimeFromRTC()
{
    RtcDateTime now = _rtc->GetDateTime();
    _hours = now.Hour();
    _minutes = now.Minute();
}

void Clock::setup()
{
    _rtc->Begin();
    Serial.println(__TIME__);
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    checkClockSetup(compiled);
    updateTimeFromRTC();
}

void Clock::loop()
{
    updateTimeFromRTC();
}