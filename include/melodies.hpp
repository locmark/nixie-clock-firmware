#pragma once

#include <Arduino.h>

#include "String.h"
#include "buzzer.hpp"
#include "notes.hpp"

struct Melody {
    String name;
    int *melody;
    int *noteDurations;
};

Melody happyBirthdayMelody = {
    .name = "Happy Birthday",
    .melody = (int[]){
        NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4,
        NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4,
        NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4,
        NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4},
    .noteDurations = (int[]){400, 400, 400, 400, 400, 200, 400, 400, 400, 400, 400, 200, 400, 400, 400, 400, 400, 400, 200, 400, 400, 400, 400, 400, 200}};

const Melody melodies[] = {
    happyBirthdayMelody,
    // add more melodies here
};