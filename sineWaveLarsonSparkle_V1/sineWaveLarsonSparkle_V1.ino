//sketch using a sine wave to smoothly transition between two colors
//larson with a sine wave while using millis to time flashes
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
float frequency = 0.00045;//larger number for faster speed

//flash speed
int flashInterval = 500;// interval at which to flash(milliseconds)Larger number for less flashing

//beginning color
uint8_t red0 = 255;
uint8_t green0 = 0;
uint8_t blue0 = 0;

//ending color
uint8_t red1 = 0;
uint8_t green1 = 0;
uint8_t blue1 = 255;

//flash color
uint8_t R = 255;
uint8_t G = 255;
uint8_t B = 255;

long flashMillis;// will store last time pixel was flashed
int n = strip.numPixels();//number of pixels in the strip
float currentS = millis();//holds the current time in milliseconds

int wait = 8;//small delay to help show the flashes. Delay stops everything, so use wisely

void setup()
{
  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop()
{
  currentS = millis();//check the current time

  for (int i = 0; i < n; i++)//loop through the number of pixels and set each at a value based on a sine wave calculation
  {
    float phase = (float)i / (float)(n - 1) * 2.0 * PI;
    float t = sin(2.0 * PI * frequency * currentS + phase);

    uint8_t red = lerp(t, -1.0, 1.0, red0, red1);//sets the color based on liniar interpolation
    uint8_t green = lerp(t, -1.0, 1.0, green0, green1);
    uint8_t blue = lerp(t, -1.0, 1.0, blue0, blue1);

    strip.setPixelColor(i, red, green, blue);

    //flash a random pixel
    if (currentS - flashMillis > flashInterval)//check to see if it's time to flash a pixel
    {
      // save the last time you flashed a pixel
      flashMillis = currentS;

      //choose a random pixel and flash it
      strip.setPixelColor((random(strip.numPixels())), R, G, B);
    }
    
    strip.show();
    delay(wait);
  }
}
