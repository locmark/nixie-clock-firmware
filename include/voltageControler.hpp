#pragma once

#include <Arduino.h>

#include "encoder.hpp"
#include "hvConverter.hpp"

#define DEFAULT_VOLTAGE 155
#define MIN_VOLTAGE_LIMIT 140
#define MAX_VOLTAGE_LIMIT 205

class VoltageControler {
   private:
    const uint8_t voltage_step = 5;
    uint8_t voltage = DEFAULT_VOLTAGE;
    Encoder encoder;
    HVConverter hvConverter;

    void initEvents() {
        encoder.setLeftCallback([this]() {
            voltage -= voltage_step;
            this->setVoltage(voltage);
        });

        encoder.setRightCallback([this]() {
            voltage += voltage_step;
            this->setVoltage(voltage);
        });
    }

    void setVoltage(int voltage) {
        if (voltage < MIN_VOLTAGE_LIMIT) {
            voltage = MIN_VOLTAGE_LIMIT;
        } else if (voltage > MAX_VOLTAGE_LIMIT) {
            voltage = MAX_VOLTAGE_LIMIT;
        }

        hvConverter.setVoltage(voltage);
    }

   public:
    VoltageControler(Encoder& encoder, HVConverter& hvConverter) : encoder(encoder), hvConverter(hvConverter) {
        this->encoder = encoder;
        this->hvConverter = hvConverter;

        initEvents();
        setVoltage(voltage);
    }

    int getDesiredVoltage() {
        return voltage;
    }
};
