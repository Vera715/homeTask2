#include <FastLED.h>
#define NUM_LEDS 54
#define DATA_PIN 9
int start = 0;
int end = 255;
int r;
int g;
int b;
CRGB leds[NUM_LEDS];
void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++ )
  {
   r = rand() % (end - start + 1) + start;
   g = rand() % (end - start + 1) + start;
   b = rand() % (end - start + 1) + start;
    leds[i] = CRGB(r, g, b);
    FastLED.show();
    delay(150);
  }
  for (int i = NUM_LEDS; i >= 0; i--)
  {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(150);
  }
}
