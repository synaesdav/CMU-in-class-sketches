//basic sketch to manipulate the onboard LED on the Circuit Playground on pin 13
//makes pin 13 blink SOS using a for loop
//written by David Crittenden 2/22

uint8_t redLed = 13;
int shortWait = 150;
int longWait = 375;
int extraLongWait = 800;

void setup()
{
  pinMode (redLed, OUTPUT);//initialize pin 13 as an output
}

void loop()
{
  //dot dot dot
  for (uint8_t i = 0; i < 3; i++)
  {
    digitalWrite(redLed, HIGH);
    delay (shortWait);
    digitalWrite(redLed, LOW);
    delay (shortWait);
  }

  //dash dash dash
  for (uint8_t i = 0; i < 3; i++)
  {
    digitalWrite(redLed, HIGH);
    delay (longWait);
    digitalWrite(redLed, LOW);
    delay (shortWait);
  }

  //dot dot dot
  for (uint8_t i = 0; i < 3; i++)
  {
    digitalWrite(redLed, HIGH);
    delay (shortWait);
    digitalWrite(redLed, LOW);
    delay (shortWait);
  }

  //wait between cycles
  delay (extraLongWait);
}
