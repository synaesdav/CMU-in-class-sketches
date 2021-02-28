//simple sketch to illustrate using a potentiometer to manipulate data
//potentiometer dims the brightness of the onboard NeoPixels
//uses serial port to display actual brightness values
//Written for Circuit Playground by David Crittenden 2/22

//potentiometer's center pin is connected to pin 10 on the Circuit Playground (able to do analog input - check the pinout of your board)
//potentiometer's outer pins - one is connected to GND, the other is connected to 3.3v+ (logic level output of the board, not VBATT)

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int potPin = 10;//center pin of the potentiometer
int potPinReading;//variable to hold the value of the reading
int brightnessLevel;//variable to hold the mapped value of the potentiometer in relationship to brightness


void setup()
{
  Serial.begin(9600); //prepares the serial port
  strip.begin();
  strip.show();
}

void loop()
{
  potPinReading = analogRead(potPin);//take a reading of potPin
  brightnessLevel = map(potPinReading, 0, 1023, 0, 255);//brigtness is expressed in values of 0-255

  strip.fill(strip.Color(200, 30, 100));//random color - try changing the values or using something else
  strip.setBrightness(brightnessLevel);//sets the brightness acording to the potPin
  strip.show();

  Serial.println(brightnessLevel);//sends the value to the serial monitor. open serial monitor after program starts.

  delay(10);//just something to keep it from going too fast, not really necessary
}
