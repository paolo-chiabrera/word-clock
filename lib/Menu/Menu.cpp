#include "Arduino.h"

#include "Menu.h"

Menu::Menu()
{
    _menuIsActive = false;
    _subMenuIsActive = false;
    _lastMenuItem = -1;
    _currentMenuItem = DEFAULT_MENU_ITEM;
    _lastSubMenuValue = -1;
    _subMenuValue = 0;
}

void Menu::clearMenu()
{
    _menuIsActive = false;
    _currentMenuItem = DEFAULT_MENU_ITEM;
    _lastMenuItem = -1;
}

void Menu::clearSubMenu()
{
    _subMenuIsActive = false;
    _lastSubMenuValue = -1;
    _subMenuValue = 0;
}

bool Menu::menuHasChanged()
{
    if (_currentMenuItem == _lastMenuItem && _subMenuValue == _lastSubMenuValue)
    {
        return false;
    }
    else
    {
        _lastMenuItem = _currentMenuItem;
        if (_subMenuIsActive)
        {
            _lastSubMenuValue = _subMenuValue;
        }
        return true;
    }
}

void Menu::onForwardScrolling()
{
    if (_menuIsActive)
    {
        if (_subMenuIsActive)
        {
            switch (_currentMenuItem)
            {
            case MENU_ITEM_HOURS:
                nextHoursValue();
                break;
            case MENU_ITEM_MINUTES:
                nextMinutesValue();
                break;
            case MENU_ITEM_BRIGHTNESS_LOW:
                nextBrightnessLowValue();
                break;
            case MENU_ITEM_BRIGHTNESS_HIGH:
                nextBrightnessHighValue();
                break;
            case MENU_ITEM_HOURS_NIGHT_START:
                nextHoursNightStartValue();
                break;
            case MENU_ITEM_HOURS_NIGHT_END:
                nextHoursNightEndValue();
                break;
            }
        }
        else
        {
            nextMenuItem();
        }
    }
}

void Menu::onBackScrolling()
{
    if (_menuIsActive)
    {
        if (_subMenuIsActive)
        {
            switch (_currentMenuItem)
            {
            case MENU_ITEM_HOURS:
                prevHoursValue();
                break;
            case MENU_ITEM_MINUTES:
                prevMinutesValue();
                break;
            case MENU_ITEM_BRIGHTNESS_LOW:
                prevBrightnessLowValue();
                break;
            case MENU_ITEM_BRIGHTNESS_HIGH:
                prevBrightnessHighValue();
                break;
            case MENU_ITEM_HOURS_NIGHT_START:
                prevHoursNightStartValue();
                break;
            case MENU_ITEM_HOURS_NIGHT_END:
                prevHoursNightEndValue();
                break;
            }
        }
        else
        {
            prevMenuItem();
        }
    }
}

void Menu::nextMenuItem()
{
    _currentMenuItem++;

    if (_currentMenuItem >= MENU_ITEM_SIZE)
    {
        _currentMenuItem = 0;
    }

    Serial.println(_currentMenuItem);
}

void Menu::prevMenuItem()
{
    _currentMenuItem--;

    if (_currentMenuItem < 0)
    {
        _currentMenuItem = MENU_ITEM_SIZE - 1;
    }

    Serial.println(_currentMenuItem);
}

void Menu::nextHoursValue()
{
    _subMenuValue++;

    if (_subMenuValue > MAX_HOURS_VALUE)
    {
        _subMenuValue = MIN_HOURS_VALUE;
    }
}

void Menu::prevHoursValue()
{
    _subMenuValue--;

    if (_subMenuValue < MIN_HOURS_VALUE)
    {
        _subMenuValue = MAX_HOURS_VALUE - 1;
    }
}

void Menu::nextMinutesValue()
{
    _subMenuValue++;

    if (_subMenuValue > MAX_MINUTES_VALUE)
    {
        _subMenuValue = MIN_MINUTES_VALUE;
    }
}

void Menu::prevMinutesValue()
{
    _subMenuValue--;

    if (_subMenuValue < MIN_MINUTES_VALUE)
    {
        _subMenuValue = MAX_MINUTES_VALUE - 1;
    }
}

void Menu::nextBrightnessLowValue()
{
    _subMenuValue++;

    if (_subMenuValue > MAX_BRIGHTNESS_LOW_VALUE)
    {
        _subMenuValue = MIN_BRIGHTNESS_LOW_VALUE;
    }
}

void Menu::prevBrightnessLowValue()
{
    _subMenuValue--;

    if (_subMenuValue < MIN_BRIGHTNESS_LOW_VALUE)
    {
        _subMenuValue = MAX_BRIGHTNESS_LOW_VALUE - 1;
    }
}

void Menu::nextBrightnessHighValue()
{
    _subMenuValue++;

    if (_subMenuValue > MAX_BRIGHTNESS_HIGH_VALUE)
    {
        _subMenuValue = MIN_BRIGHTNESS_HIGH_VALUE;
    }
}

void Menu::prevBrightnessHighValue()
{
    _subMenuValue--;

    if (_subMenuValue < MIN_BRIGHTNESS_HIGH_VALUE)
    {
        _subMenuValue = MAX_BRIGHTNESS_HIGH_VALUE - 1;
    }
}

void Menu::nextHoursNightStartValue()
{
    _subMenuValue++;

    if (_subMenuValue > MAX_HOURS_NIGHT_START_VALUE)
    {
        _subMenuValue = MIN_HOURS_NIGHT_START_VALUE;
    }
}

void Menu::prevHoursNightStartValue()
{
    _subMenuValue--;

    if (_subMenuValue < MIN_HOURS_NIGHT_START_VALUE)
    {
        _subMenuValue = MAX_HOURS_NIGHT_START_VALUE - 1;
    }
}

void Menu::nextHoursNightEndValue()
{
    _subMenuValue++;

    if (_subMenuValue > MAX_HOURS_NIGHT_END_VALUE)
    {
        _subMenuValue = MIN_HOURS_NIGHT_END_VALUE;
    }
}

void Menu::prevHoursNightEndValue()
{
    _subMenuValue--;

    if (_subMenuValue < MIN_HOURS_NIGHT_END_VALUE)
    {
        _subMenuValue = MAX_HOURS_NIGHT_END_VALUE - 1;
    }
}

void Menu::onCancel()
{
    if (_subMenuIsActive)
    {
        clearSubMenu();
        return;
    }

    if (_menuIsActive)
    {
        clearMenu();
        return;
    }
}

void Menu::setCallback(void (*callback)(uint8_t value))
{
    _callback = callback;
}

void Menu::onConfirm(uint8_t value)
{
    _callback(value);
    // if (!_menuIsActive)
    // {
    //     _menuIsActive = true;
    //     return;
    // }

    // if (!_subMenuIsActive)
    // {
    //     _lastMenuItem = _currentMenuItem;
    //     switch (_currentMenuItem)
    //     {
    //     case MENU_ITEM_HOURS:
    //         _subMenuValue = value;
    //         break;
    //     case MENU_ITEM_MINUTES:
    //         _subMenuValue = value;
    //         break;
    //     case MENU_ITEM_BRIGHTNESS_LOW:
    //         _subMenuValue = value;
    //         break;
    //     case MENU_ITEM_BRIGHTNESS_HIGH:
    //         _subMenuValue = value;
    //         break;
    //     case MENU_ITEM_HOURS_NIGHT_START:
    //         _subMenuValue = value;
    //         break;
    //     case MENU_ITEM_HOURS_NIGHT_END:
    //         _subMenuValue = value;
    //         break;
    //     }
    //     _subMenuIsActive = true;
    //     return;
    // }

    // switch (_currentMenuItem)
    // {
    // case MENU_ITEM_HOURS:
    //     cb(_subMenuValue);
    //     break;
    // case MENU_ITEM_MINUTES:
    //     updateMinutes(subMenuValue);
    //     break;
    // case MENU_ITEM_BRIGHTNESS_LOW:
    //     brightnessLow = subMenuValue;
    //     updateLEDBrightness();
    //     break;
    // case MENU_ITEM_BRIGHTNESS_HIGH:
    //     brightnessHigh = subMenuValue;
    //     updateLEDBrightness();
    //     break;
    // case MENU_ITEM_HOURS_NIGHT_START:
    //     hoursNightStart = subMenuValue;
    //     break;
    // case MENU_ITEM_HOURS_NIGHT_END:
    //     hoursNightEnd = subMenuValue;
    //     break;
    // }

    // clearSubMenu();
}
