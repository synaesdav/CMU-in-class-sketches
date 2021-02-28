//simple sketch to illustrate using a potentiometer to manipulate data
//potentiometer changes the speed of an animation
//uses serial port to display actual speed values
//Written for Circuit Playground by David Crittenden 2/22

//potentiometer's center pin is connected to pin 10 on the Circuit Playground (able to do analog input - check the pinout of your board)
//potentiometer's outer pins - one is connected to GND, the other is connected to 3.3v+ (logic level output of the board, not VBATT)

#include <Adafruit_NeoPixel.h>
#define LED_PIN 17 //onboard NeoPixels are on pin 17
#define LED_COUNT 10 //10 onboard NeoPixels

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int potPin = 10;//center pin of the potentiometer
int potPinReading;//variable to hold the value of the reading
int speedLevel;//variable to hold the mapped value of the potentiometer in relationship to speed

int slowSpeed = 750;//larger number for slower action (more delay time)
int fastSpeed = 0;//0 is as fast as the function can run (no delay time)


void setup()
{
  Serial.begin(9600); //prepares the serial port
  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop()
{
  for (uint8_t i = 0; i < strip.numPixels(); i++)
  {
    potPinReading = analogRead(potPin);//take a reading of potPin
    speedLevel = map(potPinReading, 0, 1023, slowSpeed, fastSpeed);//speed upper and lower bounds are described in the header

    strip.clear();//sets everything to black
    strip.setPixelColor(i, 255, 150, 0);//turn on one NeoPixel on this color
    strip.show();

    Serial.println(speedLevel);//sends the value to the serial monitor. open serial monitor after program starts.

    delay(speedLevel);//wait between each pixel
  }
}
