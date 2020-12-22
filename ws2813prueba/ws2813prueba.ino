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

void setup() { 
    FastLED.addLeds<WS2813, DATA_PIN, COLOR_MODE>(leds, NUM_LEDS);
    LEDS.setBrightness(40);
    
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void loop() { 
  // Turn the LED on, then pause
//  leds[0] = CRGB::Indigo;
//  FastLED.show();
//  delay(500);
//  // Now turn the LED off, then pause
//  leds[0] = CRGB::Black;
//  FastLED.show();
//  delay(500);

//  for(int i = 0; i < NUM_LEDS; i++){
//    leds[i] = CRGB::Purple;
//    FastLED.show();
//    delay(50);
//    leds[i] = CRGB::Black;
//  }

    /*Now with HSV*/
    static uint8_t hue = 0;
    static uint8_t cosa = 255;
    for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CHSV(hue++, 255, 255);
        FastLED.show();
        
        leds[i] = CRGB::Black;
        //delay(1);
    }

    for(int i = (NUM_LEDS) - 1; i >= 0; i--){
        leds[i] = CRGB::Indigo;
        FastLED.show();
        fadeall();
    }
   
    
    /*CHSV(color, saturation, brightness)
        -Lowe saturation -> close to white*/
//    leds[1] = CHSV(170, 255, 255);
//    FastLED.show();
//    delay(5);
    
  
}
