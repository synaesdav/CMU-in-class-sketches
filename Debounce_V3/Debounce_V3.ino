//simple sketch to change functionality of onboard NeoPixels using the right and left button of the Circuit Playground Classic
//buttonCheck function derived from various Adafruit projects
//Modified for the Circuit Playground Classic using the onboard switches and onboard NeoPixels
//Pressing the left button on the Circuit Playground Classic turns the NeoPixels on
//Modified by David Crittenden 2/21

//setup the NeoPixels
#include <Adafruit_NeoPixel.h>
#define LED_PIN 17
#define LED_COUNT 10
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//variables for pin numbers
uint8_t button = 4;//using the left button on the Circuit Playground Classic

//used in buttonCheck function
bool buttonPressed;//keeps track of whether the button has been pressed or not
bool newState;//stores the reading from the pin at the moment
bool oldState = LOW; //sets the initial value of the pin reading
uint8_t debounceWait = 20;//how much time to wait during debounce - larger number for noisier switches

uint32_t color = strip.Color(255, 0, 255);//custom color to be used

void setup()
{
  pinMode(button, INPUT);//initialize the switch as an input
  strip.begin();//initialize the NeoPixel object
  strip.show();
  strip.setBrightness(50);//(0-255)
}

void loop()
{
  buttonCheck();//function call to check if the button is being pressed

  if (buttonPressed == true)//the button is being pressed, light the NeoPixels
  {
    strip.fill(color);
    strip.show();
  }

  else//the button is not being pressed, turn off the NeoPixels
  {
    strip.clear();
    strip.show();
  }
}

void buttonCheck()
{
  //button check to cycle through modes
  newState = digitalRead(button); //Get the current button state

  if (newState == HIGH && oldState == LOW)//has the button been pressed
  {
    delay(debounceWait);// Short delay to debounce button.
    newState = digitalRead(button);// Check if button is still high after debounce.
    if (newState == HIGH)//the button has been pressed
    {
      buttonPressed = true;
    }
  }
  if (newState == LOW && oldState == HIGH)//the button is not being pressed
  {
    buttonPressed = false;
  }
  // Set the last button state to the old state.
  oldState = newState;
}
