//from https://learn.adafruit.com/larson-scanner-shades#arduino-code
//makes a larson scanner effect
//Converted from the original to work with Circuit Playground Classic by David Crittenden 2/22

#include <Adafruit_NeoPixel.h>

#define N_LEDS 10
#define PIN 17
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

//some variables
int pos = 0;//position of "eye
int dir = 1;//direction of "eye"
int j;//for counting
int wait = 100;//larger number for slower action


void setup()
{
  strip.begin();
  strip.setBrightness(40);
  strip.show();
}

void loop()
{
  //draw 5 pixels centered on pos. 
  //note that the color values are in hexadecimal
  //you can use r,g,b format as well as hexidecimal
  strip.setPixelColor(pos - 2, 0x100000); // Dark red
  strip.setPixelColor(pos - 1, 0x800000); // Medium red
  //strip.setPixelColor(pos, 0xFF3000); // Center pixel is brightest red
  strip.setPixelColor(pos, 255, 255, 255);//Center pixel is white in r,g,b format
  strip.setPixelColor(pos + 1, 0x800000); // Medium red
  strip.setPixelColor(pos + 2, 0x100000); // Dark red

  strip.show();
  delay(wait);

  // Rather than being sneaky and erasing just the tail pixel,
  // it's easier to erase it all and draw a new one next time.
  for (j = -2; j <= 2; j++)
  {
    strip.setPixelColor(pos + j, 0);
  }

  // Bounce off ends of strip
  pos += dir;
  if (pos < 0)
  {
    pos = 1;
    dir = -dir;
  }
  else if (pos >= strip.numPixels())
  {
    pos = strip.numPixels() - 2;
    dir = -dir;
  }
}
