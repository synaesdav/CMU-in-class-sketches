//This is a cleaned up version of a sketch I wrote a long time ago
//It shows how you can animate each pixel and then run that through a loop
//rewritten for Circuit Playground Classic by David Crittenden 2/22
//wave feature from frozen cape test sketch
//scalable to any size strip

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int introWait = 20;//setup loop intro delay
int wait = 50;//main loop delay

void setup()
{
  strip.begin();
  strip.show();
  strip.setBrightness(30);

  //Stage 1: fade in to Fuscia
  for (int r = 0; r < 255; r++)
  {
    strip.fill(strip.Color(r, 0, r));
    strip.show();
    delay(introWait);
  }
}

void loop()
{
  //wave from fuchsia to blue
  for (int i = 0; i < LED_COUNT + 10; i++)
  {
    strip.setPixelColor(i, strip.Color(170, 0, 170));//first pixel at 2/3 fuchsia
    strip.setPixelColor(i - 1, strip.Color(85, 0, 85));//following pixel at 1/3 fuchsia
    strip.setPixelColor(i - 2, strip.Color(0, 0, 0));//black out a pixel
    strip.setPixelColor(i - 3, strip.Color(0, 0, 0));//black out a pixel
    strip.setPixelColor(i - 4, strip.Color(0, 0, 85));//following pixel at 1/3 blue
    strip.setPixelColor(i - 5, strip.Color(0, 0, 170));//following pixel at 2/3 blue
    strip.setPixelColor(i - 6, strip.Color(0, 0, 255));//final pixel full blue
    strip.setPixelColor(i - 7, strip.Color(0, 0, 170));//aftershock ripple in blue
    strip.setPixelColor(i - 8, strip.Color(0, 0, 85));
    strip.setPixelColor(i - 9, strip.Color(0, 0, 170));
    strip.setPixelColor(i - 10, strip.Color(0, 0, 255));
    strip.show();
    delay(wait);
  }

  //wave from blue to fuchsia
  for (int i = LED_COUNT - 1; i > -10; i--)
  {
    strip.setPixelColor(i, strip.Color(0, 0, 170));//first pixel at 2/3 blue
    strip.setPixelColor(i + 1, strip.Color(0, 0, 85));//following pixel at 1/3 blue
    strip.setPixelColor(i + 2, strip.Color(0, 0, 0));//black out a pixel
    strip.setPixelColor(i + 3, strip.Color(0, 0, 0));//black out a pixel
    strip.setPixelColor(i + 4, strip.Color(85, 0, 85));//following pixel at 1/3 fuchsia
    strip.setPixelColor(i + 5, strip.Color(170, 0, 170));//following pixel at 2/3 fuchsia
    strip.setPixelColor(i + 6, strip.Color(255, 0, 255));//final pixel full fuchsia
    strip.setPixelColor(i + 7, strip.Color(170, 0, 170));//aftershock ripple in fuchsia
    strip.setPixelColor(i + 8, strip.Color(85, 0, 85));
    strip.setPixelColor(i + 9, strip.Color(170, 0, 170));
    strip.setPixelColor(i + 10, strip.Color(255, 0, 255));
    strip.show();
    delay(wait);
  }
}
