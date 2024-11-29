#pragma once

#include <Arduino.h>

#include <vector>

class Expander {
   private:
    uint8_t regClkPin = 9;
    uint8_t regDataPin = 10;
    uint8_t regBlPin = 11;
    uint8_t regLePin = 3;

    size_t outputCount = 0;

    std::vector<bool> outputs;

   public:
    Expander(uint8_t regClkPin, uint8_t regDataPin, uint8_t regBlPin, uint8_t regLePin, size_t outputCount) {
        this->regClkPin = regClkPin;
        this->regDataPin = regDataPin;
        this->regBlPin = regBlPin;
        this->regLePin = regLePin;
        this->outputCount = outputCount;

        pinMode(regClkPin, OUTPUT);
        pinMode(regDataPin, OUTPUT);
        pinMode(regBlPin, OUTPUT);
        pinMode(regLePin, OUTPUT);

        digitalWrite(regClkPin, LOW);
        digitalWrite(regDataPin, HIGH);
        digitalWrite(regBlPin, HIGH);
        digitalWrite(regLePin, LOW);

        this->outputs.resize(outputCount);
    }

    void send() {
        for (size_t i = 0; i < this->outputCount; i++) {
            digitalWrite(regClkPin, HIGH);
            if (this->outputs[this->outputCount - i - 1]) {
                digitalWrite(regDataPin, HIGH);
            } else {
                digitalWrite(regDataPin, LOW);
            }
            digitalWrite(regClkPin, LOW);
            esp_rom_delay_us(1);
        }

        // latch toggle
        digitalWrite(regLePin, HIGH);
        esp_rom_delay_us(1);
        digitalWrite(regLePin, LOW);
        esp_rom_delay_us(1);
    }

    void setOutput(size_t index, bool value) {
        this->outputs[index] = value;
    }
};
