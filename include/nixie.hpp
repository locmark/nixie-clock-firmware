#pragma once

#include <Arduino.h>

#include "expander.hpp"

typedef struct {
    uint8_t digit0ExtenderPin;
    uint8_t digit1ExtenderPin;
    uint8_t digit2ExtenderPin;
    uint8_t digit3ExtenderPin;
    uint8_t digit4ExtenderPin;
    uint8_t digit5ExtenderPin;
    uint8_t digit6ExtenderPin;
    uint8_t digit7ExtenderPin;
    uint8_t digit8ExtenderPin;
    uint8_t digit9ExtenderPin;
    uint8_t dotPin;
} NixiePins;

class Nixie {
   private:
    NixiePins pins;
    Expander& expander;
    uint8_t currentDigit = 0;

   public:
    Nixie(NixiePins pins, Expander& expander) : expander(expander) {
        this->pins = pins;

        pinMode(this->pins.dotPin, OUTPUT);
    }

    void setDigit(uint8_t digit) {
        this->expander.setOutput(this->currentDigit, LOW);

        switch (digit) {
            case 0:
                this->currentDigit = this->pins.digit0ExtenderPin;
                break;
            case 1:
                this->currentDigit = this->pins.digit1ExtenderPin;
                break;
            case 2:
                this->currentDigit = this->pins.digit2ExtenderPin;
                break;
            case 3:
                this->currentDigit = this->pins.digit3ExtenderPin;
                break;
            case 4:
                this->currentDigit = this->pins.digit4ExtenderPin;
                break;
            case 5:
                this->currentDigit = this->pins.digit5ExtenderPin;
                break;
            case 6:
                this->currentDigit = this->pins.digit6ExtenderPin;
                break;
            case 7:
                this->currentDigit = this->pins.digit7ExtenderPin;
                break;
            case 8:
                this->currentDigit = this->pins.digit8ExtenderPin;
                break;
            case 9:
                this->currentDigit = this->pins.digit9ExtenderPin;
                break;
            default:
                this->currentDigit = this->pins.digit0ExtenderPin;
                break;
        }

        this->expander.setOutput(this->currentDigit, HIGH);
    }

    void setDot(bool value) {
        digitalWrite(this->pins.dotPin, value);
    }
};
