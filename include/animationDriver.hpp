#pragma once

#include "expander.hpp"
#include "nixie.hpp"

class AnimationDriver {
   private:
    Expander& expander;
    Nixie& nixie;
    uint8_t desiredDigit = 0;
    uint8_t currentDigit = 0;
    bool animating = false;
    uint32_t startTime = 0;

   public:
    AnimationDriver(Expander& expander, Nixie& nixie) : expander(expander), nixie(nixie) {
        this->nixie.setDigit(this->currentDigit);
    }

    void setDigit(uint8_t digit) {
        this->desiredDigit = digit;

        if (digit == 0 && !this->animating) {
            this->animating = true;
            this->startTime = millis();
        }
    }

    void update() {
        if (this->desiredDigit == this->currentDigit) {
            return;
        }

        if (!this->animating) {
            this->nixie.setDigit(this->desiredDigit);
            this->currentDigit = this->desiredDigit;
            return;
        }

        uint8_t animationStep = (millis() - this->startTime) / 50;

        if (animationStep > 9) {
            this->animating = false;
            this->currentDigit = this->desiredDigit;
            this->nixie.setDigit(this->desiredDigit);
            return;
        }

        uint8_t animatedDigit = 9 - animationStep;
        if (animatedDigit < this->currentDigit) {
            this->nixie.setDigit(animatedDigit);
            this->currentDigit = animatedDigit;
            return;
        }

        // this->nixie.setDigit(9 - animationStep);
    }
};
