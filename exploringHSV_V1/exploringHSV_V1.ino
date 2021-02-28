//simple sketch to explore how to manipulate HSV values
//uses gamma correction


#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

uint16_t hueValue = 0;//value range 0-65535
uint8_t saturationValue = 255;//value range 0-255
uint8_t valueValue = 255;//value range 0-255
uint32_t myColor;//variable to contain the RGB value converted from HSV
uint8_t addValue = 5;//larger number for faster action

uint32_t startColor = strip.Color(0, 0, 255);//color used in startup while waiting for Serial to connect

void setup()
{
  strip.begin();
  strip.show();
  Serial.begin(9600);
  /*while (!Serial) 
  {
    strip.fill(startColor);
    strip.show();
  }*/
}

void loop()
{
  //myColor = strip.ColorHSV(hueValue, saturationValue, valueValue);
  myColor = strip.gamma32(strip.ColorHSV(hueValue, saturationValue, valueValue));
  strip.fill(myColor);
  strip.show();

  Serial.print(hueValue);
  Serial.print("---");
  Serial.print(saturationValue);
  Serial.print("---");
  Serial.print(valueValue);
  Serial.print("---");
  Serial.println(myColor);

  hueValue = hueValue + addValue;//increments hueValue by addValue
  if (hueValue > 65534)
  {
    hueValue = 0;
  }
}
