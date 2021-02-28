//simple sketch that uses random() to choose, draw and blackout groups of pixels
//white color at random brightness
//Written for Circuit Playground by David Crittenden 2/21

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//change the values of these variables for different effects
int howManyBright = 4;//how many pixels to light up at one time
int howManyDark = 0;//how many pixels to turn dark at one time

int wait = 150;// how long to wait between cycles

uint8_t lowerLevel = 50;//lowest possible value for color
uint8_t higherLevel = 255;//highest possible value for color

void setup()
{
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  randomSeed(analogRead(0));//initalize the randomizer with the input from an unconnected analog pin (pin 0)
}

void loop()
{
  for (int i = 0; i < howManyBright; i++)
  {
    uint8_t colorChosen = random(lowerLevel, higherLevel);
    //chooses a random pixel and sets it a random color within the limits defined in the header
    strip.setPixelColor(random(strip.numPixels()),colorChosen, colorChosen, colorChosen);
  }
  for (int i = 0; i < howManyDark; i++)
  {
    //chooses a random pixel and sets it to the dark color defined in the header
    strip.setPixelColor(random(strip.numPixels()), 0, 0, 0);
  }
  strip.show();
  delay(wait);
}
