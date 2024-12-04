#include <Arduino.h>

#include "HvConverter.hpp"
#include "animationDriver.hpp"
#include "buzzer.hpp"
#include "encoder.hpp"
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

constexpr uint8_t volatgeMeasurePin = 18;
constexpr uint8_t digitalPotSDAPin = 48;
constexpr uint8_t digitalPotSCLPin = 47;

Expander expander(regClkPin, regDataPin, regBlPin, regLePin, 64);
Encoder encoder(encAPin, encBPin, encBtnPin);
Buzzer buzzer(buzzerPin);
HVConverter hvConverter(volatgeMeasurePin, digitalPotSDAPin, digitalPotSCLPin);

Nixie nixie1(nixie1Pins, expander);
Nixie nixie2(nixie2Pins, expander);
Nixie nixie3(nixie3Pins, expander);
Nixie nixie4(nixie4Pins, expander);
Nixie nixie5(nixie5Pins, expander);
Nixie nixie6(nixie6Pins, expander);

AnimationDriver nixie1animated(expander, nixie1);
AnimationDriver nixie2animated(expander, nixie2);
AnimationDriver nixie3animated(expander, nixie3);
AnimationDriver nixie4animated(expander, nixie4);
AnimationDriver nixie5animated(expander, nixie5);
AnimationDriver nixie6animated(expander, nixie6);

int voltage = 160;

void setup() {
    Serial.begin(115200);

    Serial.println("[setup] Starting setup");

    WIFI_Init();
    NTP_Init();

    encoder.setLeftCallback([]() {
        voltage -= 5;

        if (voltage < 140) {
            voltage = 140;
        }

        hvConverter.setVoltage(voltage);
    });

    encoder.setRightCallback([]() {
        voltage += 5;

        if (voltage > 200) {
            voltage = 200;
        }

        hvConverter.setVoltage(voltage);
    });

    Serial.println("[setup] Finished setup");
}

bool neonState = false;

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

    // nixie1.setDigit(hourDigit1);
    // nixie2.setDigit(hourDigit2);
    // nixie3.setDigit(minuteDigit1);
    // nixie4.setDigit(minuteDigit2);

    // uint32_t voltage = hvConverter.getVoltage();
    // set voltage on nixie tubes from 1 to 6, voltage is 6 digits long

    // nixie1.setDigit(voltage / 100000);
    // nixie2.setDigit(voltage / 10000 % 10);
    // nixie3.setDigit(voltage / 1000 % 10);
    // nixie4.setDigit(voltage / 100 % 10);
    // nixie5.setDigit(voltage / 10 % 10);
    // nixie6.setDigit(voltage % 10);

    // if (encoder.getDirection() == 1) {
    //     nixie2.setDigit(1);
    // } else if (encoder.getDirection() == -1) {
    //     nixie2.setDigit(2);
    // }

    // if (encoder.isButtonPushed()) {
    //     nixie3.setDigit(1);
    //     buzzer.play();
    // } else {
    //     nixie3.setDigit(0);
    //     buzzer.stop();
    // }

    // nixie1animated.setDigit(hourDigit1);
    // nixie2animated.setDigit(hourDigit2);
    // nixie3animated.setDigit(minuteDigit1);
    // nixie4animated.setDigit(minuteDigit2);
    // nixie5animated.setDigit(secondDigit1);
    // nixie6animated.setDigit(secondDigit2);

    // nixie1animated.update();
    // nixie2animated.update();
    // nixie3animated.update();
    // nixie4animated.update();
    // nixie5animated.update();
    // nixie6animated.update();

    expander.setOutput(neon1ExpanderPin, neonState ? HIGH : LOW);
    expander.setOutput(neon2ExpanderPin, neonState ? HIGH : LOW);

    neonState = !neonState;

    encoder.update();
    expander.send();
    hvConverter.update();
    // buzzer.update();

    delay(1);
}
