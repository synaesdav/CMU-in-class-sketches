//basic sketch to manipulate the onboard LED on the Circuit Playground
//expanded to demonstrate using a transistor to switch single color 12 volt LED strip on pin 10
//expanded to demonstrate using functions
//makes pin 13 blink SOS
//makes pin 10 blink SOS
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
  dot(3);
  dash(3);
  dot(3);

  //wait between cycles
  delay (extraLongWait); 
}

void dot(uint8_t howMany)
{
  for (uint8_t i = 0; i < howMany; i++)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(otherLed, HIGH);
    delay (shortWait);
    digitalWrite(redLed, LOW);
    digitalWrite(otherLed, LOW);
    delay (shortWait);
  }
}
void dash(uint8_t howMany)
{
  for (uint8_t i = 0; i < howMany; i++)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(otherLed, HIGH);
    delay (longWait);
    digitalWrite(redLed, LOW);
    digitalWrite(otherLed, LOW);
    delay (shortWait);
  }
}
