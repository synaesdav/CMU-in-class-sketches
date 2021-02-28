//simple sketch to manipulate the onboard NeoPixels on the Circuit Playground
//makes the onboard NepPixels blink SOS without using a loop
//written by David Crittenden 2/21
//utilizes code from Adafruit's strand test

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int shortWait = 150;
int longWait = 350;
int extraLongWait = 800;

//list of possible colors
uint32_t magenta = strip.Color(255, 0, 255);
uint32_t aqua = strip.Color(0, 255, 255);
uint32_t customColor = strip.Color(27, 15, 199);

uint32_t rgbValue = strip.ColorHSV(244, 86, 78);

uint32_t myColor = customColor;//change this to change the color

void setup()
{
  strip.begin();
  strip.show();
  strip.setBrightness(50);
}

void loop()
{
  //dot dot dot
  strip.fill(myColor);
  strip.show();
  delay(shortWait);
  strip.clear();
  strip.show();
  delay(shortWait);
  strip.fill(myColor);
  strip.show();
  delay(shortWait);
  strip.clear();
  strip.show();
  delay(shortWait);
  strip.fill(myColor);
  strip.show();
  delay(shortWait);
  strip.clear();
  strip.show();
  delay(shortWait);

  delay(shortWait);

  //dash dash dash
  strip.fill(myColor);
  strip.show();
  delay(longWait);
  strip.clear();
  strip.show();
  delay(longWait);
  strip.fill(myColor);
  strip.show();
  delay(longWait);
  strip.clear();
  strip.show();
  delay(longWait);
  strip.fill(myColor);
  strip.show();
  delay(longWait);
  strip.clear();
  strip.show();
  delay(longWait);
  
//dot dot dot
  strip.fill(myColor);
  strip.show();
  delay(shortWait);
  strip.clear();
  strip.show();
  delay(shortWait);
  strip.fill(myColor);
  strip.show();
  delay(shortWait);
  strip.clear();
  strip.show();
  delay(shortWait);
  strip.fill(myColor);
  strip.show();
  delay(shortWait);
  strip.clear();
  strip.show();
  delay(shortWait);

  delay(extraLongWait);
}
