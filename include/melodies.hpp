#pragma once

#include <Arduino.h>

#include <vector>

#include "String.h"
#include "buzzer.hpp"
#include "notes.hpp"

struct Melody {
    String name;
    std::vector<int> tones;
    std::vector<int> noteDurations;
};

Melody happyBirthdayMelody = {
    .name = "Happy Birthday",
    .tones = {
        NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4,
        NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4,
        NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4,
        NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4},
    .noteDurations = {400, 400, 400, 400, 400, 200, 400, 400, 400, 400, 400, 200, 400, 400, 400, 400, 400, 400, 200, 400, 400, 400, 400, 400, 200}};

Melody gameOfThronesMelody = {
    .name = "Game of Thrones",
    .tones = {
        NOTE_G4, NOTE_C5, NOTE_DS5, NOTE_F5, NOTE_G5, NOTE_C5, NOTE_DS5, NOTE_F5,
        NOTE_G4, NOTE_C5, NOTE_DS5, NOTE_F5, NOTE_G5, NOTE_C5, NOTE_DS5, NOTE_F5,
        NOTE_G4, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_C5,
        NOTE_E5, NOTE_G5, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_C5},
    .noteDurations = {500, 500, 250, 250, 500, 500, 250, 250, 500, 500, 250, 250, 500, 500, 250, 250, 500, 500, 250, 250, 500, 500, 250, 250, 500, 500, 250, 250, 500, 500}};

Melody lordOfTheRingsMelody = {
    .name = "Lord of the Rings",
    .tones = {
        NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_A4,
        NOTE_G4, NOTE_A4, NOTE_B4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4},
    .noteDurations = {500, 250, 500, 500, 250, 500, 500, 500, 500, 250, 500, 500, 250, 500, 500, 500, 500, 250, 500, 500, 500}};

Melody barkaMelody = {
    .name = "Barka",
    .tones = {
        NOTE_F4, NOTE_F4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4,
        NOTE_A4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_F4,
        NOTE_F4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4,
        NOTE_A4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4},
    .noteDurations = {400, 400, 600, 400, 400, 400, 800,       // Pierwsza fraza
                      400, 400, 600, 400, 400, 400, 400, 800,  // Druga fraza
                      400, 400, 600, 400, 400, 400, 800,       // Trzecia fraza
                      400, 400, 600, 400, 400, 400, 800}       // Czwarta fraza
};

const Melody melodies[] = {
    happyBirthdayMelody,
    gameOfThronesMelody,
    lordOfTheRingsMelody,
    barkaMelody
    // add more melodies here
};