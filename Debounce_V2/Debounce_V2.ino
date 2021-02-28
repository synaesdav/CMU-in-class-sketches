//Debounce program derived from Arduino example code: http://www.arduino.cc/en/Tutorial/Debounce
//Modified for the Circuit Playground Classic using the onboard switches and LED
//Modified to condense into a function
//Pressing either button on the Circuit Playground Classic toggles the LED on/off
//Modified by David Crittenden 2/21

/*
  Debounce
  Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
  press), the output pin is toggled from LOW to HIGH or HIGH to LOW. There's a
  minimum delay between toggles to debounce the circuit (i.e. to ignore noise).

  created 21 Nov 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Limor Fried
  modified 28 Dec 2012
  by Mike Walters
  modified 30 Aug 2016
  by Arturo Guadalupi

  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Debounce
*/

//variables for pin numbers
uint8_t leftButtonPin = 4;
uint8_t rightButtonPin = 19;
uint8_t ledPin = 13;

//these variables can be boolean because they are either on or off
bool ledState = HIGH;//the current state of the output pin
bool rightButtonState;//the current reading from the right button
bool leftButtonState;//the current reading from the left button
bool lastRightButtonState = LOW;//the previous reading from the right button
bool lastLeftButtonState = LOW;//the previous reading from the left button

//the following variables are unsigned longs because the time, measured in
//milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastRightDebounceTime = 0;//the last time the right button was pressed
unsigned long lastLeftDebounceTime = 0;//the last time the left button was pressed
unsigned long debounceDelay = 50;//the debounce time; increase if the output flickers

void setup()
{
  pinMode(rightButtonPin, INPUT);
  pinMode(leftButtonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop()
{
  doubleButtonCheck();//check to see if either button has been pressed
  digitalWrite(ledPin, ledState);// set the LED:
}

void doubleButtonCheck()//function to check if either button has been pressed
{
  // read the state of the switch into a local variable:
  bool rightReading = digitalRead(rightButtonPin);
  bool leftReading = digitalRead(leftButtonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (rightReading != lastRightButtonState)
  {
    // reset the debouncing timer
    lastRightDebounceTime = millis();
  }
  if (leftReading != lastLeftButtonState)
  {
    // reset the debouncing timer
    lastLeftDebounceTime = millis();
  }

  if ((millis() - lastRightDebounceTime) > debounceDelay)
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (rightReading != rightButtonState)
    {
      rightButtonState = rightReading;

      // only toggle the LED if the new button state is HIGH
      if (rightButtonState == HIGH)
      {
        ledState = !ledState;
      }
    }
  }
  if ((millis() - lastLeftDebounceTime) > debounceDelay)
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (leftReading != leftButtonState)
    {
      leftButtonState = leftReading;

      // only toggle the LED if the new button state is HIGH
      if (leftButtonState == HIGH)
      {
        ledState = !ledState;
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastRightButtonState = rightReading;
  lastLeftButtonState = leftReading;
}
