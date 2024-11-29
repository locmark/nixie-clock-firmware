#include <Arduino.h>

#include "expander.hpp"
#include "nixie.hpp"
#include "nixieDefinitions.hpp"
#include "ntp.hpp"
#include "wifi.hpp"

constexpr uint8_t encAPin = 2;
constexpr uint8_t encBPin = 1;
constexpr uint8_t encBtnPin = 38;

constexpr uint8_t neon1ExpanderPin = 10;
constexpr uint8_t neon2ExpanderPin = 52;

constexpr uint8_t ledDataPin = 4;

constexpr uint8_t buzzerPin = 14;

constexpr uint8_t regClkPin = 9;
constexpr uint8_t regDataPin = 10;
constexpr uint8_t regBlPin = 11;
constexpr uint8_t regLePin = 3;

Expander expander(regClkPin, regDataPin, regBlPin, regLePin, 64);

Nixie nixie1(nixie1Pins, expander);
Nixie nixie2(nixie2Pins, expander);
Nixie nixie3(nixie3Pins, expander);
Nixie nixie4(nixie4Pins, expander);
Nixie nixie5(nixie5Pins, expander);
Nixie nixie6(nixie6Pins, expander);

void setup() {
    Serial.begin(115200);

    Serial.println("[setup] Starting setup");

    WIFI_Init();
    NTP_Init();

    Serial.println("[setup] Finished setup");
}

void loop() {
    NTP_Update();

    uint8_t hour = NTP_GetHour();
    uint8_t minute = NTP_GetMinute();
    uint8_t second = NTP_GetSecond();

    uint8_t hourDigit1 = hour / 10;
    uint8_t hourDigit2 = hour % 10;

    uint8_t minuteDigit1 = minute / 10;
    uint8_t minuteDigit2 = minute % 10;

    uint8_t secondDigit1 = second / 10;
    uint8_t secondDigit2 = second % 10;

    nixie1.setDigit(hourDigit1);
    nixie2.setDigit(hourDigit2);
    nixie3.setDigit(minuteDigit1);
    nixie4.setDigit(minuteDigit2);
    nixie5.setDigit(secondDigit1);
    nixie6.setDigit(secondDigit2);

    // nixie1.setDigit(1);
    // nixie2.setDigit(1);
    // nixie3.setDigit(1);
    // nixie4.setDigit(2);
    // nixie5.setDigit(3);
    // nixie6.setDigit(4);

    expander.send();

    delay(200);
}
