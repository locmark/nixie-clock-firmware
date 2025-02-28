#pragma once

#include <FastLED.h>

static constexpr uint8_t colorOrder = GRB;
#define chipset WS2812B
static constexpr uint8_t brightness = 200;
static constexpr uint8_t framesPerSecond = 60;

static constexpr uint8_t ledDataPin = 4;
static constexpr uint8_t ledCount = 17;
// COOLING: How much does the air cool as it rises?
// Less cooling = taller flames.  More cooling = shorter flames.
// Default 55, suggested range 20-100
#define COOLING 55

// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.
#define SPARKING 120

static bool gReverseDirection = false;

class LedStrip {
   private:
    CRGB leds[ledCount];

    CRGBPalette16 gPal;

    void Fire2012WithPalette() {
        // Array of temperature readings at each simulation cell
        static uint8_t heat[ledCount];

        // Step 1.  Cool down every cell a little
        for (int i = 0; i < ledCount; i++) {
            heat[i] = qsub8(heat[i], random8(0, ((COOLING * 10) / ledCount) + 2));
        }

        // Step 2.  Heat from each cell drifts 'up' and diffuses a little
        for (int k = ledCount - 1; k >= 2; k--) {
            heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
        }

        // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
        if (random8() < SPARKING) {
            int y = random8(7);
            heat[y] = qadd8(heat[y], random8(160, 255));
        }

        // Step 4.  Map from heat cells to LED colors
        for (int j = 0; j < ledCount; j++) {
            // Scale the heat value from 0-255 down to 0-240
            // for best results with color palettes.
            uint8_t colorindex = scale8(heat[j], 240);
            CRGB color = ColorFromPalette(gPal, colorindex);
            int pixelnumber;
            if (gReverseDirection) {
                pixelnumber = (ledCount - 1) - j;
            } else {
                pixelnumber = j;
            }
            leds[pixelnumber] = color;
        }
    }

   public:
    LedStrip() {
        FastLED.addLeds<chipset, ledDataPin, GRB>(leds, (int)ledCount).setCorrection(TypicalLEDStrip);
        FastLED.setBrightness(brightness);

        // This first palette is the basic 'black body radiation' colors,
        // which run from black to red to bright yellow to white.
        gPal = HeatColors_p;
    }

    void update() {
        random16_add_entropy(random());
        Fire2012WithPalette();  // run simulation frame, using palette colors

        FastLED.show();  // display this frame
        FastLED.delay(1000 / framesPerSecond);
    }
};