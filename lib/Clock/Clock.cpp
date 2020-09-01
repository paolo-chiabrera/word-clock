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
    if (!_rtc->IsDateTimeValid())
    {
        // Common Causes:
        //    1) first time you ran and the device wasn't running yet
        //    2) the battery on the device is low or even missing
        Serial.println("RTC lost confidence in the DateTime!");
        _rtc->SetDateTime(compiled);
    }

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

    RtcDateTime now = _rtc->GetDateTime();

    if (now < compiled)
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        _rtc->SetDateTime(compiled);
    }
    else if (now > compiled)
    {
        Serial.println("RTC is newer than compile time. (this is expected)");
    }
    else if (now == compiled)
    {
        Serial.println("RTC is the same as compile time! (not expected but all is fine)");
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
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    checkClockSetup(compiled);
    updateTimeFromRTC();
}

void Clock::loop() {
    updateTimeFromRTC();
}