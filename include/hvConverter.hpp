#pragma once

#include <Arduino.h>
#include <Wire.h>

#include <vector>

#define POT_ADDRESS 0b0101111

#define ADC_OFFSET 10
#define ADC_REF_VOLTAGE 3.3

class HVConverter {
   private:
    uint8_t volatgeMeasurePin = 18;
    uint8_t digitalPotSDAPin = 48;
    uint8_t digitalPotSCLPin = 47;

    uint8_t dpMaxSteps = 128;
    uint8_t absoluteMinVoltage = 130;
    uint8_t absoluteMaxVoltage = 220;

    uint8_t maxVoltageLimit = 200;
    uint8_t minVoltageLimit = 140;

    int measureVoltageInterval = 100;
    unsigned long lastIntervalTime = millis();

    int maxRangeOhms = 10000;
    uint32_t measuredVoltage = 0;

    void sendData(uint8_t data) {
        Wire.beginTransmission(POT_ADDRESS);
        Wire.write(data);
        Wire.endTransmission();
    }

    int voltageToSteps(uint8_t voltage) {
        return (voltage - absoluteMinVoltage) * dpMaxSteps / (absoluteMaxVoltage - absoluteMinVoltage);
    }

   public:
    HVConverter(uint8_t volatgeMeasurePin, uint8_t digitalPotSDAPin, uint8_t digitalPotSCLPin) {
        this->volatgeMeasurePin = volatgeMeasurePin;
        this->digitalPotSDAPin = digitalPotSDAPin;
        this->digitalPotSCLPin = digitalPotSCLPin;

        pinMode(volatgeMeasurePin, INPUT);
        Wire.begin(digitalPotSDAPin, digitalPotSCLPin, 100000);
        analogReadResolution(10);
    }

    void setVoltage(uint8_t voltage) {
        if (voltage < absoluteMinVoltage) {
            voltage = absoluteMinVoltage;
        } else if (voltage > absoluteMaxVoltage) {
            voltage = absoluteMaxVoltage;
        } else if (voltage > maxVoltageLimit) {
            voltage = maxVoltageLimit;
        } else if (voltage < minVoltageLimit) {
            voltage = minVoltageLimit;
        }

        sendData(voltageToSteps(voltage));
    }

    void update() {
        if (millis() - lastIntervalTime < measureVoltageInterval) {
            return;
        }

        measuredVoltage = int32_t(analogReadMilliVolts(volatgeMeasurePin) * 0.475 - 28.774);
        lastIntervalTime = millis();
    }

    int getVoltage() {
        return measuredVoltage;
    }
};
