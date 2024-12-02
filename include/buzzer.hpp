#pragma once

#include <Arduino.h>

#include "notes.hpp"

// Define the "Happy Birthday" melody
int melody[] = {
    NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4,           // "Happy Birthday to You"
    NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4,           // "Happy Birthday to You"
    NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4,  // "Happy Birthday dear [Name]"
    NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4          // "Happy Birthday to You"
};

// Define the note durations
int noteDurations[] = {
    400, 400, 400, 400, 400, 200,
    400, 400, 400, 400, 400, 200,
    400, 400, 400, 400, 400, 400, 200,
    400, 400, 400, 400, 400, 200};

// Liczba nut w melodii
const int melodyLength = sizeof(melody) / sizeof(melody[0]);

class Buzzer {
   private:
    uint8_t buzzerPin;
    bool isPlaying;
    int currentNote;
    unsigned long lastNoteTime;
    float tempoMultiplier;

   public:
    Buzzer(uint8_t buzzerPin, float tempoMultiplier = 1.0)
        : buzzerPin(buzzerPin), isPlaying(false), currentNote(0), lastNoteTime(0), tempoMultiplier(tempoMultiplier) {
        pinMode(buzzerPin, OUTPUT);
    }

    void setTempo(float multiplier) {
        tempoMultiplier = multiplier;
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

        int adjustedNoteDuration = noteDurations[currentNote] / tempoMultiplier;

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
