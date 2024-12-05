#pragma once

#include <Arduino.h>
#include <Wire.h>

#include <vector>

#define ADC_FUN_A 0.475
#define ADC_FUN_B -28.774

#define MAX_VOLTAGE 210
#define MIN_VOLTAGE 134
#define OFFSET_VOLTAGE 4

#define POT_ADDRESS 0b0101111
#define POT_STEPS 127

class HVConverter {
   private:
    uint8_t volatgeMeasurePin = 18;
    uint8_t digitalPotSDAPin = 48;
    uint8_t digitalPotSCLPin = 47;

    uint32_t measureVoltageInterval = 1000;
    unsigned long lastIntervalTime = millis();

    int maxRangeOhms = 10000;
    uint32_t measuredVoltage = 0;
    uint8_t _steps = 0;

    void sendPotSteps(uint8_t steps) {
        _steps = steps;
        Wire.beginTransmission(POT_ADDRESS);
        Wire.write(steps);
        Wire.endTransmission();
    }

    int voltageToSteps(uint8_t voltage) {
        return (voltage + OFFSET_VOLTAGE - MIN_VOLTAGE) * POT_STEPS / (MAX_VOLTAGE - MIN_VOLTAGE);
    }

   public:
    HVConverter(uint8_t volatgeMeasurePin, uint8_t digitalPotSDAPin, uint8_t digitalPotSCLPin) {
        this->volatgeMeasurePin = volatgeMeasurePin;
        this->digitalPotSDAPin = digitalPotSDAPin;
        this->digitalPotSCLPin = digitalPotSCLPin;

        pinMode(volatgeMeasurePin, INPUT);
        Wire.begin(digitalPotSDAPin, digitalPotSCLPin, 100000);
        // fix, on 12 bits resolution measurment beacomse not linear
        analogReadResolution(10);
    }

    void setVoltage(uint8_t voltage) {
        if (voltage < MIN_VOLTAGE) {
            voltage = MIN_VOLTAGE;
        } else if (voltage > MAX_VOLTAGE) {
            voltage = MAX_VOLTAGE;
        }

        sendPotSteps(voltageToSteps(voltage));
    }

    void update() {
        if (millis() - lastIntervalTime < measureVoltageInterval) {
            return;
        }

        measuredVoltage = analogReadMilliVolts(volatgeMeasurePin) * ADC_FUN_A + ADC_FUN_B;
        lastIntervalTime = millis();
    }

    int getMeasuredVoltage() {
        return measuredVoltage;
    }

    int getSteps() {
        return _steps;
    }
};
