//needs work

//simple sketch to demonstrate how a for loop can be used to manipulate data
//makes a cluster of pixels circle around in a ring
//expanded to add changing color to the pixel cluster
//uses the arithmetic operator %(modulo) to help a value rollover from 9 to 0
//see Arduino reference for further examples and syntax of %
//written for Circuit Playground Classic
//written by David Crittenden 2/22

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int wait = 400;//used in the for loop
uint8_t howMuch = 20;//factor used in color morphing - larger number for faster color morphing

//variables to hold rgb color values try playing with some of these
uint8_t rFirst = 255;
uint8_t gFirst = 0;
uint8_t bFirst = 0;
uint8_t rSecond = 0;
uint8_t gSecond = 255;
uint8_t bSecond = 0;
uint8_t rThird = 0;
uint8_t gThird = 0;
uint8_t bThird = 255;


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
    //first set the value of some color variables
    //play with which variables you use to affect the color differently
    rFirst = rFirst + howMuch;//adds howMuch to the value every time through the loop
    if (rFirst > 255)
    {
      rFirst = 0;//resets the value to 0 so it doesn't exceed the value limit
    }
    bSecond = bSecond + howMuch;//adds howMuch to the value every time through the loop
    if (bSecond > 255)
    {
      bSecond = 0;//resets the value to 0 so it doesn't exceed the value limit
    }
    gThird = gThird + howMuch;//adds howMuch to the value every time through the loop
    if (gThird > 255)
    {
      gThird = 0;//resets the value to 0 so it doesn't exceed the value limit
    }


    strip.clear();//turns everything off - play with removing this line entirely or placing outside of the for loop
    strip.setPixelColor(i, rThird, gThird, bThird);//sets the pixel with the same value as i, a color expressed in RGB
    strip.setPixelColor(((i + 1) % strip.numPixels()), rSecond, gSecond, bSecond); //sets the pixel before i another color
    strip.setPixelColor(((i + 2) % strip.numPixels()), rFirst, gFirst, bFirst); //uses modulo % to wrap around the ring - see in reference

    //strip.setPixelColor(i+1, 0, 255, 0);//sets the pixel above i another color
    strip.show();
    delay(wait);
  }
}
