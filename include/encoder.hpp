#pragma once

#include <Arduino.h>

#include <vector>

class Encoder {
   private:
    uint8_t pinA = 2;
    uint8_t pinB = 1;
    uint8_t switchPin = 38;

    int8_t direction = 0;
    int8_t pulseCounter = 5;
    bool buttonPushed = false;
    bool buttonReleased = false;

    std::function<void()> rightCallback;
    std::function<void()> leftCallback;
    std::function<void()> switchPressCallback;
    std::function<void()> switchReleaseCallback;

   public:
    Encoder(uint8_t pinA, uint8_t pinB, uint8_t switchPin) {
        this->pinA = pinA;
        this->pinB = pinB;
        this->switchPin = switchPin;

        pinMode(pinA, INPUT);
        pinMode(pinB, INPUT);
        pinMode(switchPin, INPUT_PULLUP);
    }

    int getDirection() {
        return direction;
    }

    int getPulseCounter() {
        return pulseCounter;
    }

    bool isButtonPushed() {
        return buttonPushed;
    }

    bool isButtonReleased() {
        return buttonReleased;
    }

    void setRightCallback(std::function<void()> callback) {
        this->rightCallback = callback;
    }

    void setLeftCallback(std::function<void()> callback) {
        this->leftCallback = callback;
    }

    void setSwitchPressCallback(std::function<void()> callback) {
        this->switchPressCallback = callback;
    }

    void setSwitchReleaseCallback(std::function<void()> callback) {
        this->switchReleaseCallback = callback;
    }

    void update() {
        if (digitalRead(switchPin) == LOW) {
            if (!buttonPushed) {
                buttonPushed = true;
                buttonReleased = false;
                if (switchPressCallback) {
                    switchPressCallback();
                }
            }
        } else {
            if (buttonPushed) {
                buttonPushed = false;
                buttonReleased = true;
                if (switchReleaseCallback) {
                    switchReleaseCallback();
                }
            }
        }

        static uint8_t lastEncoded = 0;
        static uint8_t encoded = 0;
        static const int8_t transitions[] = {0, 1, -1, 0, -1, 0, 0, 1, 1, 0, 0, -1, 0, 1, -1, 0};
        static uint8_t state = 0;

        lastEncoded <<= 2;
        lastEncoded |= (digitalRead(pinA) << 1) | digitalRead(pinB);
        encoded = lastEncoded & 0x0f;

        direction = transitions[state * 4 + encoded];
        state = encoded;

        if (direction == 1) {
            pulseCounter++;
            if (rightCallback) {
                rightCallback();
            }
        } else if (direction == -1) {
            pulseCounter--;
            if (leftCallback) {
                leftCallback();
            }
        }
    }
};
