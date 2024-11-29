#pragma once

#include <nixie.hpp>

constexpr uint8_t dot1Pin = 5;
constexpr uint8_t dot2Pin = 17;
constexpr uint8_t dot3Pin = 8;
constexpr uint8_t dot4Pin = 12;
constexpr uint8_t dot5Pin = 13;
constexpr uint8_t dot6Pin = 21;

const NixiePins nixie6Pins = {
    .digit0ExtenderPin = 32,
    .digit1ExtenderPin = 41,
    .digit2ExtenderPin = 40,
    .digit3ExtenderPin = 39,
    .digit4ExtenderPin = 38,
    .digit5ExtenderPin = 37,
    .digit6ExtenderPin = 36,
    .digit7ExtenderPin = 35,
    .digit8ExtenderPin = 34,
    .digit9ExtenderPin = 33,
    .dotPin = dot1Pin,
};

const NixiePins nixie5Pins = {
    .digit0ExtenderPin = 42,
    .digit1ExtenderPin = 51,
    .digit2ExtenderPin = 50,
    .digit3ExtenderPin = 49,
    .digit4ExtenderPin = 48,
    .digit5ExtenderPin = 47,
    .digit6ExtenderPin = 46,
    .digit7ExtenderPin = 45,
    .digit8ExtenderPin = 44,
    .digit9ExtenderPin = 43,
    .dotPin = dot2Pin,
};

const NixiePins nixie4Pins = {
    .digit0ExtenderPin = 53,
    .digit1ExtenderPin = 62,
    .digit2ExtenderPin = 61,
    .digit3ExtenderPin = 60,
    .digit4ExtenderPin = 59,
    .digit5ExtenderPin = 58,
    .digit6ExtenderPin = 57,
    .digit7ExtenderPin = 56,
    .digit8ExtenderPin = 55,
    .digit9ExtenderPin = 54,
    .dotPin = dot3Pin,
};

const NixiePins nixie3Pins = {
    .digit0ExtenderPin = 0,
    .digit1ExtenderPin = 9,
    .digit2ExtenderPin = 8,
    .digit3ExtenderPin = 7,
    .digit4ExtenderPin = 6,
    .digit5ExtenderPin = 5,
    .digit6ExtenderPin = 4,
    .digit7ExtenderPin = 3,
    .digit8ExtenderPin = 2,
    .digit9ExtenderPin = 1,
    .dotPin = dot4Pin,
};

const NixiePins nixie2Pins = {
    .digit0ExtenderPin = 11,
    .digit1ExtenderPin = 20,
    .digit2ExtenderPin = 19,
    .digit3ExtenderPin = 18,
    .digit4ExtenderPin = 17,
    .digit5ExtenderPin = 16,
    .digit6ExtenderPin = 15,
    .digit7ExtenderPin = 14,
    .digit8ExtenderPin = 13,
    .digit9ExtenderPin = 12,
    .dotPin = dot5Pin,
};

const NixiePins nixie1Pins = {
    .digit0ExtenderPin = 22,
    .digit1ExtenderPin = 31,
    .digit2ExtenderPin = 30,
    .digit3ExtenderPin = 29,
    .digit4ExtenderPin = 28,
    .digit5ExtenderPin = 27,
    .digit6ExtenderPin = 26,
    .digit7ExtenderPin = 25,
    .digit8ExtenderPin = 24,
    .digit9ExtenderPin = 23,
    .dotPin = dot6Pin,
};