//basic sketch to manipulate the onboard LED on the Circuit Playground on pin 13
//expanded to demonstrate using a transistor to switch single color 12 volt LED strip on pin 10
//makes pin 13 blink SOS using a loop
//makes pin 10 blink SOS using a loop
//written by David Crittenden 2/22

uint8_t redLed = 13;
uint8_t otherLed = 10;
int shortWait = 150;
int longWait = 375;
int extraLongWait = 800;

void setup()
{
  pinMode (redLed, OUTPUT);//initialize pin 13 as an output
  pinMode (otherLed, OUTPUT);//initialize pin 10 as an output
}

void loop()
{
  //dot dot dot
  for (uint8_t i = 0; i < 3; i++)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(otherLed, HIGH);
    delay (shortWait);
    digitalWrite(redLed, LOW);
    digitalWrite(otherLed, LOW);
    delay (shortWait);
  }

  //dash dash dash
  for (uint8_t i = 0; i < 3; i++)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(otherLed, HIGH);
    delay (longWait);
    digitalWrite(redLed, LOW);
    digitalWrite(otherLed, LOW);
    delay (shortWait);
  }

  //dot dot dot
  for (uint8_t i = 0; i < 3; i++)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(otherLed, HIGH);
    delay (shortWait);
    digitalWrite(redLed, LOW);
    digitalWrite(otherLed, LOW);
    delay (shortWait);
  }

  //wait between cycles
  delay (extraLongWait);
}
