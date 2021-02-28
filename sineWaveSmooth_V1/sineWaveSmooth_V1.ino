//sketch using a sine wave to smoothly transition between two colors
//all pixels set to the same color
//based on code from Fairy Wings project for Randy Carfagno / Zina Brown
//Written by David Crittenden 4/15/2017
//major update 2/21 rewritten for Circuit Playground
//incorporating code https://github.com/adafruit/CircuitPlayground_Power_Reactor

#include "lerp.h"//other tab containing the formula for liniar interpolation

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//speed of sine wave
float frequency = 0.00015;//larger number for faster speed

//beginning color
uint8_t red0 = 255;
uint8_t green0 = 150;
uint8_t blue0 = 0;

//ending color
uint8_t red1 = 70;
uint8_t green1 = 0;
uint8_t blue1 = 225;

float currentS;//holds the current time in milliseconds

void setup()
{
  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop()
{
  currentS = millis();//check the current time
  float t = sin(2.0 * PI * frequency * currentS);

  uint8_t red = lerp(t, -1.0, 1.0, red0, red1);//sets the color based on liniar interpolation
  uint8_t green = lerp(t, -1.0, 1.0, green0, green1);
  uint8_t blue = lerp(t, -1.0, 1.0, blue0, blue1);

  strip.fill(strip.Color(red, green, blue));

  strip.show();
}
