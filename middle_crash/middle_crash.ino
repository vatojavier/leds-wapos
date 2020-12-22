#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 300

// Color mode
# define COLOR_MODE GRB

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 7
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

int ascIndex;
int descIndex;


void setup() { 
    FastLED.addLeds<WS2813, DATA_PIN, COLOR_MODE>(leds, NUM_LEDS);
    LEDS.setBrightness(100);
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void loop() { 
    
    for(int i = 0; i < NUM_LEDS; i++){
        ascIndex = i;
        descIndex = NUM_LEDS-1-i;
        
        leds[ascIndex] = CRGB::Indigo;
        leds[descIndex] = CRGB::Blue;
        
        FastLED.show();
        //delay(1);

        leds[ascIndex] = CRGB::Black;
        leds[descIndex] = CRGB::Black;

        if(ascIndex == (descIndex -1 )){
            leds[ascIndex] = CRGB::Red;
            FastLED.show();
            delay(40);
        }
        
    }
}
