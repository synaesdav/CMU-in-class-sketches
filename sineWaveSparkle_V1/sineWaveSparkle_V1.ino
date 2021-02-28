//working code
//Fairy Wings for Randy Carfagno / Zina Brown
//Written by David Crittenden 4/15/2017
//incorporating code from:
//https://github.com/adafruit/CircuitPlayground_Power_Reactor

//larson with a sine wave while using millis to time flashes

#include <Adafruit_NeoPixel.h>
#include "lerp.h"

//#ifdef __AVR__
//#include <avr/power.h>
//#endif

#define PIN 9
#define PINA 10
#define PINB 11
#define PINC 12

Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, PIN, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel stripA = Adafruit_NeoPixel(10, PINA, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel stripB = Adafruit_NeoPixel(10, PINB, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel stripC = Adafruit_NeoPixel(10, PINC, NEO_RGB + NEO_KHZ800);

//speed of sine wave
float frequency = 0.0004;//larger number for faster speed

//flash speed
long flashInterval = 100;// interval at which to flash (milliseconds)

//beginning color
uint8_t red0 = 20;
uint8_t green0 = 70;
uint8_t blue0 = 0;

//ending color
uint8_t red1 = 0;
uint8_t green1 = 175;
uint8_t blue1 = 30;

//flash color
uint8_t R = 40;
uint8_t G = 255;
uint8_t B = 40;

long flashMillis = 0;// will store last time pixel was flashed

uint8_t flash;

void setup()
{
  strip.begin();
  strip.show();
  stripA.begin();
  stripA.show();
  stripB.begin();
  stripB.show();
  stripC.begin();
  stripC.show();// Initialize all pixels to 'off'
}

void loop()
{
//larson with a sine wave
  uint16_t n = 10;//number of pixels
  float currentS = millis();
  
  for (int i = 0; i < n; i++)
  {
    float phase = (float)i / (float)(n - 1) * 2.0 * PI;
    float t = sin(2.0 * PI * frequency * currentS + phase);

    uint8_t red = lerp(t, -1.0, 1.0, red0, red1);
    uint8_t green = lerp(t, -1.0, 1.0, green0, green1);
    uint8_t blue = lerp(t, -1.0, 1.0, blue0, blue1);

    strip.setPixelColor(i, red, green, blue);
    strip.show();
    stripA.setPixelColor(i, red, green, blue);
    stripA.show();
    stripB.setPixelColor(i, red, green, blue);
    stripB.show();
    stripC.setPixelColor(i, red, green, blue);
    stripC.show();
  }




  //flash a random number of pixels
  // check to see if it's time to flash the pixel
  unsigned long currentMillis = millis();
  if (currentMillis - flashMillis > flashInterval)
  {
    // save the last time you blinked the LED
    flashMillis = currentMillis;

    //choose another random pixel to light up
    flash = random(10);
    strip.setPixelColor(flash, R, G, B);
    strip.show();
    //choose another random pixel to light up
    flash = random(10);
    stripA.setPixelColor(flash, R, G, B);
    stripA.show();
    //choose another random pixel to light up
    flash = random(10);
    stripB.setPixelColor(flash, R, G, B);
    stripB.show();
    //choose another random pixel to light up
    flash = random(10);
    stripC.setPixelColor(flash, R, G, B);
    stripC.show();
  }

}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c)
{
  for (uint16_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, c);
    stripA.setPixelColor(i, c);
    stripB.setPixelColor(i, c);
    stripC.setPixelColor(i, c);
    strip.show();
    stripA.show();
    stripB.show();
    stripC.show();
  }
}
