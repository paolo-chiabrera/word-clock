#ifndef Menu_h
#define Menu_h

#include "Arduino.h"

#define DEFAULT_MENU_ITEM 0
#define MENU_ITEM_SIZE 6
#define MENU_ITEM_HOURS 0
#define MENU_ITEM_MINUTES 1
#define MENU_ITEM_BRIGHTNESS_LOW 2
#define MENU_ITEM_BRIGHTNESS_HIGH 3
#define MENU_ITEM_HOURS_NIGHT_START 4
#define MENU_ITEM_HOURS_NIGHT_END 5

#define MAX_HOURS_VALUE 24
#define MIN_HOURS_VALUE 1
#define MAX_MINUTES_VALUE 59
#define MIN_MINUTES_VALUE 0
#define MAX_BRIGHTNESS_LOW_VALUE 120
#define MIN_BRIGHTNESS_LOW_VALUE 1
#define MAX_BRIGHTNESS_HIGH_VALUE 120
#define MIN_BRIGHTNESS_HIGH_VALUE 1
#define MAX_HOURS_NIGHT_START_VALUE 24
#define MIN_HOURS_NIGHT_START_VALUE 1
#define MAX_HOURS_NIGHT_END_VALUE 24
#define MIN_HOURS_NIGHT_END_VALUE 1

class Menu
{
private:
    bool _menuIsActive = false;
    bool _subMenuIsActive = false;
    int _lastMenuItem = -1;
    int _currentMenuItem = DEFAULT_MENU_ITEM;
    int _lastSubMenuValue = -1;
    int _subMenuValue = 0;
    void (*_callback)(uint8_t);

public:
    Menu();
    void clearMenu();
    void clearSubMenu();
    bool menuHasChanged();
    void nextMenuItem();
    void prevMenuItem();
    void onCancel();
    void onConfirm(uint8_t value = 0);
    void nextHoursValue();
    void prevHoursValue();
    void nextMinutesValue();
    void prevMinutesValue();
    void nextBrightnessLowValue();
    void prevBrightnessLowValue();
    void nextBrightnessHighValue();
    void prevBrightnessHighValue();
    void nextHoursNightStartValue();
    void prevHoursNightStartValue();
    void nextHoursNightEndValue();
    void prevHoursNightEndValue();
    void onForwardScrolling();
    void onBackScrolling();
    void setCallback(void (*callback)(uint8_t value));
};

#endif