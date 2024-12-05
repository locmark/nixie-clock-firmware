#pragma once
#include <Arduino.h>

#include <vector>

#include "melodies.hpp"

class Buzzer {
   private:
    uint8_t buzzerPin;
    bool isPlaying;
    int currentNote;
    unsigned long lastNoteTime;

    Melody melody = barkaMelody;

   public:
    Buzzer(uint8_t buzzerPin)
        : buzzerPin(buzzerPin), isPlaying(false), currentNote(0), lastNoteTime(0) {
        pinMode(buzzerPin, OUTPUT);
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
        int adjustedNoteDuration = melody.noteDurations[currentNote];
        if (currentTime - lastNoteTime >= adjustedNoteDuration * 1.30) {
            noTone(buzzerPin);
            currentNote++;
            if (currentNote >= melody.tones.size()) {
                stop();
                return;
            }
            lastNoteTime = currentTime;
        }
        if (melody.tones[currentNote] != 0 &&
            currentTime - lastNoteTime < adjustedNoteDuration) {
            tone(buzzerPin, melody.tones[currentNote]);
        }
    }
};