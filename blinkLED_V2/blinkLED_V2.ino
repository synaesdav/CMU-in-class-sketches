//sketch written in Session 2 class
//blink the onboard LED
//blink NeoPixels

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int ledPin = 13;//onboard led on pin 13
int shortWait = 200;//value to delay the blink
int longWait = 500;
int bigWait = 750;

int i = 0;//used for counting

//list of possible colors
uint32_t magenta = strip.Color(255, 0, 255);
uint32_t aqua = strip.Color(0, 255, 255);
uint32_t customColor = strip.Color(27, 15, 199);


void setup()
{
  strip.begin();
  strip.show();
  strip.setBrightness(50);

  pinMode(ledPin, OUTPUT);//declares pin 13 as output

}

void loop()
{
  dot(3);//dot dot dot
  dash(3);//dash dash dash
  dot(3);//dot dot dot
  
  delay (bigWait);//wait between cycles
}

void dot(int howMany)
{
  for (i = 0; i < howMany; i++)
  {
    digitalWrite(ledPin, HIGH);//turns the LED on
    strip.fill(magenta);
    strip.show();
    delay(shortWait);
    digitalWrite(ledPin, LOW);//turns the led off
    strip.clear();
    strip.show();
    delay(shortWait);

  }
}

void dash(int howMany)
{
  for (i = 0; i < howMany; i++)
  {
    digitalWrite(ledPin, HIGH);//turns the LED on
    strip.fill(aqua);
    strip.show();
    delay(longWait);
    digitalWrite(ledPin, LOW);//turns the led off
    strip.clear();
    strip.show();
    delay(longWait);
  }
}
