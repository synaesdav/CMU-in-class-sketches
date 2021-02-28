//simple sketch to change NeoPixel functionality using the onboard slide switch and push buttons
//written for Circuit Playground Classic
//includes buttonCheck(); expanded to leftButtonCheck(); and rightButtonCheck();
//written by David Crittenden 2/22

//setup the NeoPixels
#include <Adafruit_NeoPixel.h>
#define LED_PIN 17
#define LED_COUNT 10
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//variables for pin numbers
uint8_t leftButtonPin = 4;
uint8_t rightButtonPin = 19;
uint8_t button = 4;
uint8_t slideSwitch = 21;

//used in buttonCheck function
bool buttonPressed;//keeps track of whether the button has been pressed or not
bool newState;//stores the reading from the pin at the moment
bool oldState = LOW; //sets the initial value of the pin reading

//used in leftButtonCheck function
bool leftButtonPressed;//keeps track of whether the button has been pressed or not
bool leftNewState;//stores the reading from the pin at the moment
bool leftOldState = LOW; //sets the initial value of the pin reading

//used in rightButtonCheck function
bool rightButtonPressed;//keeps track of whether the button has been pressed or not
bool rightNewState;//stores the reading from the pin at the moment
bool rightOldState = LOW; //sets the initial value of the pin reading

bool slideState;//value of the slide switch reading
uint8_t debounceWait = 20;//how much time to wait during debounce - larger number for noisier switches

void setup()
{
  pinMode(leftButtonPin, INPUT);//initialize the switch pins as inputs
  pinMode(rightButtonPin, INPUT);
  pinMode(slideSwitch, INPUT);

  strip.begin();//initialize the NeoPixel object
  strip.show();
  strip.setBrightness(30);//(0-255)
}

void loop()
{
  slideState = digitalRead(slideSwitch);//check to see if the pin is high or low, right or left

  if (slideState == LOW)//slide switch is in the left position
  {
    leftButtonCheck();//get a reading from the left button
    if (leftButtonPressed == true)
    {
      //do this
    }
    rightButtonCheck();//get a reading from the right button
    if (rightButtonPressed == true)
    {
      //do this
    }
    else
    {
      //do this
    }
  }

  if (slideState == HIGH)//slide switch is in the right position
  {
    leftButtonCheck();//get a reading from the left button
    if (leftButtonPressed == true)
    {
      //do this
    }
    rightButtonCheck();//get a reading from the right button
    if (rightButtonPressed == true)
    {
      //do this
    }
    else
    {
      //do this
    }
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

void leftButtonCheck()
{
  //button check to cycle through modes
  leftNewState = digitalRead(leftButtonPin); //Get the current button state

  if (leftNewState == HIGH && leftOldState == LOW)//has the button been pressed?
  {
    delay(debounceWait);// Short delay to debounce button.
    leftNewState = digitalRead(leftButtonPin);// Check if button is still high after debounce.
    if (leftNewState == HIGH)//the button has been pressed
    {
      leftButtonPressed = true;
    }
  }
  if (leftNewState == LOW && leftOldState == HIGH)//the button is not being pressed
  {
    leftButtonPressed = false;
  }
  // Set the last button state to the old state.
  leftOldState = leftNewState;
}

void rightButtonCheck()
{
  //button check to cycle through modes
  rightNewState = digitalRead(rightButtonPin); //Get the current button state

  if (rightNewState == HIGH && rightOldState == LOW)//has the button been pressed?
  {
    delay(debounceWait);// Short delay to debounce button.
    rightNewState = digitalRead(rightButtonPin);// Check if button is still high after debounce.
    if (rightNewState == HIGH)//the button has been pressed
    {
      rightButtonPressed = true;
    }
  }
  if (rightNewState == LOW && rightOldState == HIGH)//the button is not being pressed
  {
    rightButtonPressed = false;
  }
  // Set the last button state to the old state.
  rightOldState = rightNewState;
}
