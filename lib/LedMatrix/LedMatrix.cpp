#include "Arduino.h"
#include "FastLED.h"

#include "LedMatrix.h"

CRGB PALETTE[] = {
    CRGB(249, 237, 105),
    CRGB(240, 138, 93),
    CRGB(184, 59, 94),
    CRGB(106, 44, 112),
    CRGB(243, 129, 129),
    CRGB(252, 227, 138),
    CRGB(234, 255, 208),
    CRGB(149, 225, 211),
    CRGB(248, 95, 115),
    CRGB(251, 232, 211),
    CRGB(146, 138, 151),
    CRGB(40, 60, 99),
    CRGB(7, 104, 159),
    CRGB(162, 213, 242),
    CRGB(250, 250, 250),
    CRGB(255, 126, 103),
    CRGB(168, 230, 207),
    CRGB(253, 255, 171),
    CRGB(255, 211, 182),
    CRGB(255, 170, 165),
    CRGB(12, 5, 109),
    CRGB(89, 13, 130),
    CRGB(182, 26, 174),
    CRGB(242, 93, 156),
    CRGB(21, 82, 99),
    CRGB(255, 111, 60),
    CRGB(255, 154, 60),
    CRGB(255, 201, 60),
    CRGB(255, 100, 100),
    CRGB(255, 130, 100),
    CRGB(255, 170, 100),
    CRGB(255, 245, 165),
    CRGB(248, 181, 149),
    CRGB(246, 114, 128),
    CRGB(192, 108, 132),
    CRGB(108, 91, 124),
    CRGB(39, 41, 109),
    CRGB(94, 99, 182),
    CRGB(163, 147, 235),
    CRGB(245, 199, 247),
    CRGB(54, 79, 107),
    CRGB(63, 193, 201),
    CRGB(245, 245, 245),
    CRGB(252, 81, 133),
    CRGB(168, 216, 234),
    CRGB(170, 150, 218),
    CRGB(252, 186, 211),
    CRGB(255, 255, 210),
    CRGB(0, 184, 169),
    CRGB(248, 243, 212),
    CRGB(246, 65, 108),
    CRGB(255, 222, 125),
    CRGB(72, 70, 109),
    CRGB(61, 132, 168),
    CRGB(70, 205, 207),
    CRGB(171, 237, 216),
    CRGB(226, 62, 87),
    CRGB(136, 48, 78),
    CRGB(82, 37, 70),
    CRGB(49, 29, 63),
    CRGB(246, 114, 128),
    CRGB(192, 108, 132),
    CRGB(108, 91, 123),
    CRGB(53, 92, 125),
    CRGB(254, 226, 179),
    CRGB(255, 162, 153),
    CRGB(173, 105, 137),
    CRGB(86, 35, 73),
    CRGB(241, 227, 203),
    CRGB(249, 179, 132),
    CRGB(202, 81, 22),
    CRGB(88, 28, 12),
    CRGB(88, 180, 174),
    CRGB(255, 226, 119),
    CRGB(255, 179, 103),
    CRGB(255, 226, 188),
    CRGB(246, 245, 120),
    CRGB(246, 215, 67),
    CRGB(100, 157, 102),
    CRGB(6, 98, 59),
    CRGB(255, 82, 0),
    CRGB(111, 0, 0),
    CRGB(0, 38, 59),
    CRGB(0, 161, 171),
    CRGB(248, 243, 235),
    CRGB(195, 237, 234),
    CRGB(252, 126, 47),
    CRGB(244, 5, 82),
    CRGB(188, 101, 141),
    CRGB(130, 196, 195),
    CRGB(249, 216, 156),
    CRGB(245, 167, 167),
    CRGB(234, 144, 122),
    CRGB(251, 198, 135),
    CRGB(244, 247, 197),
    CRGB(170, 205, 190),
    CRGB(217, 32, 39),
    CRGB(255, 146, 52),
    CRGB(255, 205, 60),
    CRGB(53, 208, 186),
    CRGB(126, 189, 180),
    CRGB(246, 209, 152),
    CRGB(244, 165, 72),
    CRGB(134, 42, 92),
    CRGB(48, 57, 96),
    CRGB(234, 154, 150),
    CRGB(248, 178, 79),
    CRGB(229, 229, 229),
    CRGB(255, 211, 29),
    CRGB(214, 52, 71),
    CRGB(245, 123, 81),
    CRGB(246, 238, 223),
    CRGB(255, 216, 166),
    CRGB(252, 130, 16),
    CRGB(255, 66, 127),
    CRGB(0, 120, 146),
    CRGB(95, 221, 229),
    CRGB(244, 234, 142),
    CRGB(243, 113, 33),
    CRGB(217, 32, 39),
    CRGB(252, 248, 118),
    CRGB(55, 151, 164),
    CRGB(140, 203, 190),
    CRGB(228, 228, 228),
    CRGB(250, 238, 231),
    CRGB(245, 66, 145),
    CRGB(76, 211, 194),
    CRGB(10, 151, 176),
    CRGB(232, 228, 225),
    CRGB(249, 196, 154),
    CRGB(236, 130, 58),
    CRGB(124, 60, 33),
    CRGB(244, 246, 255),
    CRGB(243, 198, 35),
    CRGB(18, 118, 129),
    CRGB(16, 55, 92),
    CRGB(101, 64, 98),
    CRGB(255, 156, 113),
    CRGB(251, 212, 109),
    CRGB(232, 234, 211),
    CRGB(17, 29, 94),
    CRGB(199, 0, 57),
    CRGB(243, 113, 33),
    CRGB(255, 189, 105),
    CRGB(182, 235, 122),
    CRGB(247, 247, 238),
    CRGB(251, 120, 19),
    CRGB(23, 112, 110),
    CRGB(244, 246, 255),
    CRGB(255, 203, 116),
    CRGB(234, 144, 122),
    CRGB(79, 138, 139),
    CRGB(162, 222, 150),
    CRGB(60, 165, 157),
    CRGB(90, 61, 85),
    CRGB(231, 156, 42),
    CRGB(56, 62, 86),
    CRGB(246, 158, 123),
    CRGB(238, 218, 209),
    CRGB(212, 181, 176),
    CRGB(185, 172, 146),
    CRGB(255, 169, 49),
    CRGB(254, 203, 137),
    CRGB(251, 230, 212),
    CRGB(250, 38, 160),
    CRGB(5, 223, 215),
    CRGB(163, 247, 191),
    CRGB(255, 245, 145),
};

int NUMBER_OF_PALETTES = sizeof(PALETTE) / PALETTE_SIZE / 3;

LedMatrix::LedMatrix(uint8_t ledsNumber)
{
    _columns = 12;
    _rows = 10;
    _ledsNumber = ledsNumber;
    _leds = new CRGB[ledsNumber];
    _blockNumber = random(0, NUMBER_OF_PALETTES) * PALETTE_SIZE;
}

void LedMatrix::clearMatrix()
{
    for (int i = 0; i < _ledsNumber; i++)
    {
        _leds[i] = CRGB::Black;
    }
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

uint8_t LedMatrix::matrixToArrayIndex(uint8_t row, uint8_t col)
{
    if (row % 2 == 0)
    {
        return row * _columns + col;
    }

    return (row + 1) * _columns - col - 1;
}

void LedMatrix::setCell(uint8_t row, uint8_t col, CRGB colour = CRGB::White)
{
    _leds[matrixToArrayIndex(row, col)] = colour;
}

void LedMatrix::setColumn(uint8_t col, CRGB colour = CRGB::White)
{
    for (int i = 0; i <= _rows; i++)
    {
        _leds[matrixToArrayIndex(i, col)] = colour;
    }
}

void LedMatrix::showValue(uint8_t value, CRGB colour = CRGB::White)
{
    clearMatrix();

    uint8_t dec = (uint8_t)floor(value / 10);
    uint8_t digit = (uint8_t)(value % 10);

    if (dec > 9)
    {
        dec = 9;
    }

    String indexes = "_" + String(_digitLeft[dec]) + "_" + String(_digitRight[digit]) + "_";

    for (int i = 0; i < _ledsNumber; i++)
    {
        if (indexes.indexOf("_" + String(i) + "_") >= 0)
        {
            _leds[i] = colour;
        }
        else
        {
            _leds[i] = CRGB::Black;
        }
    }

    FastLED.show();
}

void LedMatrix::showHumidity(uint8_t humidity)
{
    // humidity ratio between 0 and 100
    uint8_t factor = floor(humidity / 10);
    uint8_t saturation = 150 + factor * 10;

    showValue(humidity, CHSV(170, saturation, 255));
}

void LedMatrix::showTemperature(uint8_t temperature)
{
    // temperature ratio between 0 and 50
    uint8_t factor = floor(temperature * 10 / 50);
    uint8_t saturation = 150 + factor * 10;

    showValue(temperature, CHSV(0, saturation, 255));
}

String LedMatrix::getIndexes(uint8_t minutes, uint8_t hours)
{
    String output = "_";

    if (minutes >= 5 && minutes < 10)
    {
        output += FIVE_MINUTES_PAST;
    }
    else if (minutes >= 10 && minutes < 15)
    {
        output += TEN_MINUTES_PAST;
    }
    else if (minutes >= 15 && minutes < 20)
    {
        output += FIFTEEN_MINUTES_PAST;
    }
    else if (minutes >= 20 && minutes < 25)
    {
        output += TWENTY_MINUTES_PAST;
    }
    else if (minutes >= 25 && minutes < 30)
    {
        output += TWENTY_FIVE_MINUTES_PAST;
    }
    else if (minutes >= 30 && minutes < 35)
    {
        output += HALF_PAST;
    }
    else if (minutes >= 35 && minutes < 40)
    {
        output += TWENTY_FIVE_MINUTES_TO;
    }
    else if (minutes >= 40 && minutes < 45)
    {
        output += TWENTY_MINUTES_TO;
    }
    else if (minutes >= 45 && minutes < 50)
    {
        output += FIFTEEN_MINUTES_TO;
    }
    else if (minutes >= 50 && minutes < 55)
    {
        output += TEN_MINUTES_TO;
    }
    else if (minutes >= 55 && minutes < 60)
    {
        output += FIVE_MINUTES_TO;
    }

    output += "_";

    switch (hours)
    {
    case 12:
        output += isNextHour(minutes) ? ONE : TWELVE;
        break;
    case 1:
    case 13:
        output += isNextHour(minutes) ? TWO : ONE;
        break;
    case 2:
    case 14:
        output += isNextHour(minutes) ? THREE : TWO;
        break;
    case 3:
    case 15:
        output += isNextHour(minutes) ? FOUR : THREE;
        break;
    case 4:
    case 16:
        output += isNextHour(minutes) ? FIVE : FOUR;
        break;
    case 5:
    case 17:
        output += isNextHour(minutes) ? SIX : FIVE;
        break;
    case 6:
    case 18:
        output += isNextHour(minutes) ? SEVEN : SIX;
        break;
    case 7:
    case 19:
        output += isNextHour(minutes) ? EIGHT : SEVEN;
        break;
    case 8:
    case 20:
        output += isNextHour(minutes) ? NINE : EIGHT;
        break;
    case 9:
    case 21:
        output += isNextHour(minutes) ? TEN : NINE;
        break;
    case 10:
    case 22:
        output += isNextHour(minutes) ? ELEVEN : TEN;
        break;
    case 11:
    case 23:
        output += isNextHour(minutes) ? MIDNIGHT : ELEVEN;
        break;
    default:
        output += isNextHour(minutes) ? ONE : MIDNIGHT;
        break;
    }

    if (minutes < 5 && hours != 0)
    {
        output += "_";
        output += OCLOCK;
    }

    output += "_";

    return output;
}

void LedMatrix::setLowLight(bool nightMode)
{
    if (nightMode)
    {
        FastLED.setBrightness(3);
    }
    else
    {
        FastLED.setBrightness(255);
    }
}

void LedMatrix::update(uint8_t minutes, uint8_t hours, bool changeColour = false)
{
    String indexes = getIndexes(minutes, hours);

    int colourIndex = -1;
    int lastIndex = -1;

    if (changeColour)
    {
        _blockNumber = random(0, NUMBER_OF_PALETTES) * PALETTE_SIZE;
    }

    for (int i = 0; i < _ledsNumber; i++)
    {
        if (indexes.indexOf("_" + String(i) + "_") >= 0)
        {
            if (i - lastIndex > 1)
            {
                colourIndex++;
            }

            if (colourIndex >= PALETTE_SIZE)
            {
                colourIndex = 0;
            }

            // _leds[i] = nightMode ? NIGHT_COLOUR : PALETTE[_blockNumber + colourIndex];
            _leds[i] = PALETTE[_blockNumber + colourIndex];

            lastIndex = i;
        }
        else
        {
            _leds[i] = CRGB::Black;
        }
    }

    FastLED.show();
}

void LedMatrix::setup()
{
    FastLED.addLeds<CHIPSET, LED_MATRIX_PIN, COLOR_ORDER>(_leds, _ledsNumber);
}