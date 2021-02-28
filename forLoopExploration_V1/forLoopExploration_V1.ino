//simple sketch to demonstrate how a for loop can be used to manipulate data
//written for Circuit Playground Classic
//written by David Crittenden 2/22

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int wait = 100;//used in the for loop


void setup()
{
  strip.begin();
  strip.show();
  strip.setBrightness(50);
}

void loop()
{
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.clear();//turns everything off - play with removing this line entirely or placing outside of the for loop
    strip.setPixelColor(i, 255, 0, 255);//sets the pixel with the same value as i, a color expressed in RGB
    strip.show();
    delay(wait);
  }
}
