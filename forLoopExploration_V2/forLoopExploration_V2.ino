//simple sketch to demonstrate how a for loop can be used to manipulate data
//makes a cluster of pixels circle around in a ring
//uses the arithmetic operator %(modulo) to help a value rollover from 9 to 0 
//see Arduino reference for further examples and syntax of %
//written for Circuit Playground Classic
//written by David Crittenden 2/22

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int wait = 250;//used in the for loop


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
    strip.setPixelColor(i, 255, 0, 150);//sets the pixel with the same value as i, a color expressed in RGB
    strip.setPixelColor(((i + 1)%strip.numPixels()), 100, 255, 0);//sets the pixel before i another color
    strip.setPixelColor(((i + 2)%strip.numPixels()), 0, 100, 150);//uses modulo % to wrap around the ring - see in reference
    
    //strip.setPixelColor(i+1, 0, 255, 0);//sets the pixel above i another color
    strip.show();
    delay(wait);
  }
}
