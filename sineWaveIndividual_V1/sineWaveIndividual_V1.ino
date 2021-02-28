//sketch using a sine wave to smoothly transition between two colors
//each pixel operates on its own randomized sine wave frequency
//based on code from blackSmithLamp_V3 project for Randy Carfagno
//Written by David Crittenden 4/15/2017
//major update 2/21 rewritten for Circuit Playground
//incorporating code https://github.com/adafruit/CircuitPlayground_Power_Reactor

#include "lerp.h"//other tab containing the formula for liniar interpolation

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

float currentS;//variable to hold current time

//speed of sine wave
float frequencies[LED_COUNT];//array to hold individual frequencies
float f0 = 0.00001;//slowest speed a frequency could be
float f1 = 0.0005;//fastest speed a frequency could be

//beginning color
uint8_t red0 = 0;
uint8_t green0 = 255;
uint8_t blue0 = 0;

//ending color
uint8_t red1 = 30;
uint8_t green1 = 0;
uint8_t blue1 = 30;

unsigned long currentMillis = millis();

void setup()
{
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  randomSeed(analogRead(0));//initalize the randomizer with the input from an unconnected analog pin

  //fill an array with randomized frequencies
  for (int i = 0; i < strip.numPixels(); i++)
  {
    frequencies[i] = lerp(random(4096), 0, 4095, f0, f1);//4096 represents 12 bit resolution
  }
}

void loop()
{
  currentS = millis();//get the current time

  for (int i = 0; i < strip.numPixels(); i++)
  {
    float t = sin(2.0 * PI * frequencies[i] * currentS);

    uint8_t red = lerp(t, -1.0, 1.0, red0, red1);
    uint8_t green = lerp(t, -1.0, 1.0, green0, green1);
    uint8_t blue = lerp(t, -1.0, 1.0, blue0, blue1);

    strip.setPixelColor(i, strip.Color(red, green, blue));
  }
  strip.show();
}
