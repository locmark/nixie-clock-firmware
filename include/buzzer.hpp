#pragma once

#include <Arduino.h>

#include "melodies.hpp"
#include "notes.hpp"

class Buzzer {
   private:
    int *melody;
    int *noteDurations;
    int melodyLength = 0;

    uint8_t buzzerPin = 14;
    bool isPlaying = false;
    int currentNote = 0;
    unsigned long lastNoteTime = millis();

   public:
    Buzzer(uint8_t buzzerPin) {
        pinMode(buzzerPin, OUTPUT);
    }

    void setMelody(int *melody, int *noteDurations) {
        this->melody = melody;
        this->noteDurations = noteDurations;
        this->melodyLength = sizeof(melody) / sizeof(melody[0]);
    }

    void play() {
        if (isPlaying) {
            return;
        }

        isPlaying = true;
        currentNote = 0;
        lastNoteTime = millis();
    }

    void stop() {
        if (!isPlaying) {
            return;
        }

        noTone(buzzerPin);
        isPlaying = false;
        currentNote = 0;
    }

    void update() {
        if (!isPlaying) {
            return;
        }

        unsigned long currentTime = millis();

        int adjustedNoteDuration = noteDurations[currentNote];

        if (currentTime - lastNoteTime >= adjustedNoteDuration * 1.30) {
            noTone(buzzerPin);
            currentNote++;

            if (currentNote >= melodyLength) {
                stop();
                return;
            }

            lastNoteTime = currentTime;
        }

        if (melody[currentNote] != 0 &&
            currentTime - lastNoteTime < adjustedNoteDuration) {
            tone(buzzerPin, melody[currentNote]);
        }
    }
};
