//simple sketch that uses random() to choose, draw and blackout groups of pixels
//Written for Circuit Playground by David Crittenden 2/21

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//change the values of these variables for different effects
int howManyBright = 4;//how many pixels to light up at one time
int howManyDark = 3;//how many pixels to turn dark at one time
int wait = 300;// how long to wait between cycles

//lowest possible color values
uint8_t red0 = 10;
uint8_t green0 = 20;
uint8_t blue0 = 60;

//highest possible color values
uint8_t red1 = 0;
uint8_t green1 = 255;
uint8_t blue1 = 255;

//color values for the dark pixel
uint8_t redDark = 0;
uint8_t greenDark = 0;
uint8_t blueDark = 50;

void setup()
{
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  randomSeed(analogRead(0));//initalize the randomizer with the input from an unconnected analog pin
}

void loop()
{
  for (int i = 0; i < howManyBright; i++)
  {
    //chooses a random pixel and sets it a random color within the limits defined in the header
    strip.setPixelColor(random(strip.numPixels()), random(red0, red1), random(green0, green1), random(blue0, blue1));
  }
  for (int i = 0; i < howManyDark; i++)
  {
    //chooses a random pixel and sets it to the dark color defined in the header
    strip.setPixelColor(random(strip.numPixels()), redDark, greenDark, random(blueDark));
  }
  strip.show();
  delay(wait);
}
