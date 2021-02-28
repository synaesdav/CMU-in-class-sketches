//simple sketch to change NeoPixel functionality using the onboard slide switch and push buttons
//written for Circuit Playground Classic
//removed buttonCheck();
//written by David Crittenden 2/22

//setup the NeoPixels
#include <Adafruit_NeoPixel.h>
#define LED_PIN 17
#define LED_COUNT 10
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//variables for pin numbers
uint8_t leftButtonPin = 4;
uint8_t rightButtonPin = 19;
uint8_t slideSwitch = 21;

//some colors
uint32_t magenta = strip.Color(255, 0, 255);
uint32_t yellow = strip.Color(255, 255, 0);
uint32_t aqua = strip.Color(0, 255, 255);
uint32_t white = strip.Color(255, 255, 255);

bool rightButton;//value of the button reading
bool leftButton;
bool slideState;//value of the slide switch reading

void setup()
{
  pinMode(leftButtonPin, INPUT);//initialize the switch pins as inputs
  pinMode(rightButtonPin, INPUT);
  pinMode(slideSwitch, INPUT);

  strip.begin();//initialize the NeoPixel object
  strip.show();
  strip.setBrightness(40);//(0-255)
}

void loop()
{
  slideState = digitalRead(slideSwitch);//check to see if the pin is high or low, right or left

  if (slideState == LOW)//slide switch is in the left position
  {
    rightButton = digitalRead(rightButtonPin);
    leftButton = digitalRead(leftButtonPin);

    if (rightButton == HIGH)
    {
      strip.fill(magenta);
      strip.show();
    }
    if (leftButton == HIGH)
    {
      strip.fill(yellow);
      strip.show();
    }
    else
    {
      strip.clear();
      strip.show();
    }

  }

  if (slideState == HIGH)//slide switch is in the right position
  {
    rightButton = digitalRead(rightButtonPin);
    leftButton = digitalRead(leftButtonPin);

    if (rightButton == HIGH)
    {
      strip.fill(aqua);
      strip.show();
    }
    if (leftButton == HIGH)
    {
      strip.fill(white);
      strip.show();
    }
    else
    {
      strip.clear();
      strip.show();
    }
  }
}
