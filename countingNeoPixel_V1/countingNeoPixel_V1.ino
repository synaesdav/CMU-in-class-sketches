//simple sketch to turn on and off each onboard NeoPixel using a for loop
//written for Circuit Playground Classic
//written by David Crittenden 2/22

//setup the NeoPixels
#include <Adafruit_NeoPixel.h>
#define LED_PIN 17
#define LED_COUNT 10
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

uint8_t wait = 80;//larger number for slower action

void setup()
{
  strip.begin();//initialize the NeoPixel object
  strip.show();
  strip.setBrightness(30);//(0-255)
}

void loop()
{
  for (uint8_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, 255, 150, 0);//turn each NeoPixel on this color
    strip.show();
    delay(wait);//wait between each pixel
  }

  for (uint8_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, 100, 0, 255);//turn each NeoPixel on this color
    strip.show();
    delay(wait);//wait between each pixel
  }
}
