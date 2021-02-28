//simple sketch to illustrate using a potentiometer to manipulate data
//potentiometer fades through hue values and displays them on the onboard NeoPixels
//uses serial port to display actual hue values
//Written for Circuit Playground by David Crittenden 2/22

//potentiometer's center pin is connected to pin 10 on the Circuit Playground (able to do analog input - check the pinout of your board)
//potentiometer's outer pins - one is connected to GND, the other is connected to 3.3v+ (logic level output of the board, not VBATT)

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int potPin = 10;//center pin of the potentiometer
int potPinReading;//variable to hold the value of the reading
uint32_t hueValue;//variable to hold the mapped value of the potentiometer in relationship to the full spectrum of hues


void setup()
{
  Serial.begin(9600); //prepares the serial port
  strip.begin();
  strip.setBrightness(50);
  strip.show();

}

void loop()
{
  potPinReading = analogRead(potPin);//take a reading of potPin
  hueValue = map(potPinReading, 0, 1023, 0, 65535);//360 degrees of hue values is expressed in value range 0-65535

  strip.fill(strip.ColorHSV(hueValue));//turns the NeoPixels the hue value
  strip.show();

  Serial.println(hueValue);//sends the value to the serial monitor. open serial monitor after program starts.

  delay(10);//just something to keep it from going too fast, not really necessary
}
