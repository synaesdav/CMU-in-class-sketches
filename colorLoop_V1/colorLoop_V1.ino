//simple sketch to show how the loop can manipulate color values
//written for Circuit Playground Classic
//written by David Crittenden 2/22

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int wait = 10;//larger number for slower action

//some variables to hold color values
//try changing the starting value for different effects (0-255)
uint8_t r = 150;
uint8_t g = 0;
uint8_t b = 0;

void setup()
{
  strip.begin();//initialize the NeoPixel strip
  strip.show();
  strip.setBrightness(50);
}

void loop()
{
  //try commenting and uncommenting different sections for different effects
  r++;//adds 1 to the value each time through the loop
  if (r > 255)
  {
    r = 0;//resets the value to 0 so it doesn't exceed the value limit
  }
  /*g++;//adds 1 to the value each time through the loop
    if (g > 255)
    {
      g = 0;//resets the value to 0 so it doesn't exceed the value limit
    }*/
  b++;//adds 1 to the value each time through the loop
  if (b > 255)
  {
    b = 0;//resets the value to 0 so it doesn't exceed the value limit
  }

  strip.fill(strip.Color(r, g, b));
  strip.show();
  delay(wait);

}
