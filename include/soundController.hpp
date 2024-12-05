#pragma once

#include <Arduino.h>

#include "buzzer.hpp"
#include "encoder.hpp"
#include "melodies.hpp"

class SoundController {
   private:
    Buzzer& buzzer;
    Encoder& encoder;

    void initEvents() {
        encoder.setSwitchPressCallback([this]() {
            buzzer.play();
        });

        encoder.setRightCallback([this]() {
            buzzer.stop();
        });
    }

   public:
    SoundController(Encoder& encoder, Buzzer& buzzer) : encoder(encoder), buzzer(buzzer) {
        this->encoder = encoder;
        this->buzzer = buzzer;

        // seting up default melody
        buzzer.setMelody(happyBirthdayMelody.melody, happyBirthdayMelody.noteDurations);
        initEvents();
    }
};
