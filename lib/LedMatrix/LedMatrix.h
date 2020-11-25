#ifndef LedMatrix_h
#define LedMatrix_h

#include "Arduino.h"
#include "FastLED.h"

#define COLOR_ORDER GRB
#define CHIPSET WS2812B
#define LED_MATRIX_PIN 15

#define OCLOCK "108_109_110_111_112_113"
#define MIDNIGHT "99_100_101_102_103_104_105_106"
#define ONE "49_50_51"
#define TWO "37_38_39"
#define THREE "60_61_62_63_64"
#define FOUR "73_74_75_76"
#define FIVE "92_93_94_95"
#define SIX "84_85_86"
#define SEVEN "115_116_117_118_119"
#define EIGHT "67_68_69_70_71"
#define NINE "87_88_89_90"
#define TEN "96_97_98"
#define ELEVEN "53_54_55_56_57_58"
#define TWELVE "78_79_80_81_82_83"
#define FIVE_MINUTES_PAST "20_21_22_23_29_30_31_32_33_34_35_44_45_46_47"
#define TEN_MINUTES_PAST "9_10_11_29_30_31_32_33_34_35_44_45_46_47"
#define FIFTEEN_MINUTES_PAST "12_13_14_15_16_17_18_29_30_31_32_33_34_35_44_45_46_47"
#define TWENTY_MINUTES_PAST "1_2_3_4_5_6_29_30_31_32_33_34_35_44_45_46_47"
#define TWENTY_FIVE_MINUTES_PAST "1_2_3_4_5_6_20_21_22_23_29_30_31_32_33_34_35_44_45_46_47"
#define HALF_PAST "25_26_27_28_44_45_46_47"
#define TWENTY_FIVE_MINUTES_TO "1_2_3_4_5_6_20_21_22_23_29_30_31_32_33_34_35_41_42"
#define TWENTY_MINUTES_TO "1_2_3_4_5_6_29_30_31_32_33_34_35_41_42"
#define FIFTEEN_MINUTES_TO "12_13_14_15_16_17_18_29_30_31_32_33_34_35_41_42"
#define TEN_MINUTES_TO "9_10_11_29_30_31_32_33_34_35_41_42"
#define FIVE_MINUTES_TO "20_21_22_23_29_30_31_32_33_34_35_41_42"

#define ZERO_LEFT "25_26_27_28_43_46_49_52_67_70_73_76_91_94_97_100_115_116_117_118"
#define ONE_LEFT "28_43_52_67_76_91_100_115"
#define TWO_LEFT "25_26_27_28_43_52_67_68_69_70_73_94_97_115_116_117_118"
#define THREE_LEFT "25_26_27_28_43_52_67_68_69_70_76_91_100_115_116_117_118"
#define FOUR_LEFT "28_43_52_67_76_91_100_115_25_46_49_70_69_68"
#define FIVE_LEFT "25_26_27_28_46_49_67_68_69_70_76_91_100_115_116_117_118"
#define SIX_LEFT "25_26_27_28_46_49_67_68_69_70_76_91_100_115_116_117_118_73_94_97"
#define SEVEN_LEFT "25_26_27_28_43_52_67_76_91_100_115"
#define EIGHT_LEFT "25_26_27_28_43_46_49_52_67_68_69_70_73_76_91_94_97_100_115_116_117_118"
#define NINE_LEFT "25_26_27_28_43_46_49_52_67_68_69_70_76_91_100_115_116_117_118"

#define ZERO_RIGHT "31_32_33_34_37_40_55_58_61_64_79_82_85_88_103_106_109_110_111_112"
#define ONE_RIGHT "34_37_58_61_82_85_106_109"
#define TWO_RIGHT "31_32_33_34_37_58_61_62_63_64_79_88_103_109_110_111_112"
#define THREE_RIGHT "31_32_33_34_37_58_61_62_63_64_82_85_106_109_110_111_112"
#define FOUR_RIGHT "34_37_58_61_82_85_106_109_31_40_55_64_63_62"
#define FIVE_RIGHT "31_32_33_34_40_55_61_62_63_64_82_85_106_109_110_111_112"
#define SIX_RIGHT "31_32_33_34_40_55_61_62_63_64_82_85_106_109_110_111_112_79_88_103"
#define SEVEN_RIGHT "31_32_33_34_37_58_61_82_85_106_109"
#define EIGHT_RIGHT "31_32_33_34_37_40_55_58_61_62_63_64_79_82_85_88_103_106_109_110_111_112"
#define NINE_RIGHT "31_32_33_34_37_40_55_58_61_62_63_64_82_85_106_109_110_111_112"

#define PALETTE_SIZE 4

#define NIGHT_COLOUR CRGB::Grey

class LedMatrix
{
private:
    CRGB *_leds = NULL;
    uint8_t _ledsNumber;
    uint8_t _blockNumber = 0;
    uint8_t _columns = 12;
    uint8_t _rows = 10;
    String _digitLeft[10] = {ZERO_LEFT, ONE_LEFT, TWO_LEFT, THREE_LEFT, FOUR_LEFT, FIVE_LEFT, SIX_LEFT, SEVEN_LEFT, EIGHT_LEFT, NINE_LEFT};
    String _digitRight[10] = {ZERO_RIGHT, ONE_RIGHT, TWO_RIGHT, THREE_RIGHT, FOUR_RIGHT, FIVE_RIGHT, SIX_RIGHT, SEVEN_RIGHT, EIGHT_RIGHT, NINE_RIGHT};

public:
    LedMatrix(uint8_t ledsNumber = 120);
    void setup();
    bool isNextHour(int minutes = 0);
    void testLights(CRGB colour = CRGB::White);
    String getIndexes(uint8_t minutes, uint8_t hours);
    void update(uint8_t minutes, uint8_t hours, bool changeColour);
    void clearMatrix();
    void showValue(uint8_t value, CRGB colour);
    void showHumidity(uint8_t humidity);
    uint8_t matrixToArrayIndex(uint8_t row, uint8_t col);
    void setColumn(uint8_t col, CRGB colour);
    void setCell(uint8_t row, uint8_t col, CRGB colour);
    void showTemperature(uint8_t temperature);
    void setLowLight(bool nightMode);
};

#endif