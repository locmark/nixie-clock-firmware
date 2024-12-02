#pragma once

#include <nixie.hpp>

constexpr uint8_t dot1Pin = 5;
constexpr uint8_t dot2Pin = 17;
constexpr uint8_t dot3Pin = 8;
constexpr uint8_t dot4Pin = 12;
constexpr uint8_t dot5Pin = 13;
constexpr uint8_t dot6Pin = 21;

const NixiePins nixie6Pins = {
    .digit0ExtenderPin = 33,
    .digit1ExtenderPin = 32,
    .digit2ExtenderPin = 41,
    .digit3ExtenderPin = 40,
    .digit4ExtenderPin = 39,
    .digit5ExtenderPin = 38,
    .digit6ExtenderPin = 37,
    .digit7ExtenderPin = 36,
    .digit8ExtenderPin = 35,
    .digit9ExtenderPin = 34,
    .dotPin = dot1Pin,
};

const NixiePins nixie5Pins = {
    .digit0ExtenderPin = 43,
    .digit1ExtenderPin = 42,
    .digit2ExtenderPin = 51,
    .digit3ExtenderPin = 50,
    .digit4ExtenderPin = 49,
    .digit5ExtenderPin = 48,
    .digit6ExtenderPin = 47,
    .digit7ExtenderPin = 46,
    .digit8ExtenderPin = 45,
    .digit9ExtenderPin = 44,
    .dotPin = dot2Pin,
};

const NixiePins nixie4Pins = {
    .digit0ExtenderPin = 54,
    .digit1ExtenderPin = 53,
    .digit2ExtenderPin = 62,
    .digit3ExtenderPin = 61,
    .digit4ExtenderPin = 60,
    .digit5ExtenderPin = 59,
    .digit6ExtenderPin = 57,
    .digit7ExtenderPin = 57,
    .digit8ExtenderPin = 56,
    .digit9ExtenderPin = 55,
    .dotPin = dot3Pin,
};

const NixiePins nixie3Pins = {
    .digit0ExtenderPin = 1,
    .digit1ExtenderPin = 0,
    .digit2ExtenderPin = 9,
    .digit3ExtenderPin = 8,
    .digit4ExtenderPin = 7,
    .digit5ExtenderPin = 6,
    .digit6ExtenderPin = 5,
    .digit7ExtenderPin = 4,
    .digit8ExtenderPin = 3,
    .digit9ExtenderPin = 2,
    .dotPin = dot4Pin,
};

const NixiePins nixie2Pins = {
    .digit0ExtenderPin = 12,
    .digit1ExtenderPin = 11,
    .digit2ExtenderPin = 20,
    .digit3ExtenderPin = 19,
    .digit4ExtenderPin = 18,
    .digit5ExtenderPin = 17,
    .digit6ExtenderPin = 16,
    .digit7ExtenderPin = 15,
    .digit8ExtenderPin = 14,
    .digit9ExtenderPin = 13,
    .dotPin = dot5Pin,
};

const NixiePins nixie1Pins = {
    .digit0ExtenderPin = 23,
    .digit1ExtenderPin = 22,
    .digit2ExtenderPin = 31,
    .digit3ExtenderPin = 30,
    .digit4ExtenderPin = 29,
    .digit5ExtenderPin = 28,
    .digit6ExtenderPin = 27,
    .digit7ExtenderPin = 26,
    .digit8ExtenderPin = 25,
    .digit9ExtenderPin = 24,
    .dotPin = dot6Pin,
};