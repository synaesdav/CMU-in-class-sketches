//basic sketch to manipulate the onboard LED on the Circuit Playground on pin 13
//makes pin 13 blink SOS
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
  delay (longWait);
  digitalWrite(redLed, HIGH);
  delay (shortWait);
  digitalWrite(redLed, LOW);
  delay (shortWait);
  digitalWrite(redLed, HIGH);
  delay (shortWait);
  digitalWrite(redLed, LOW);
  delay (shortWait);
  digitalWrite(redLed, HIGH);
  delay (shortWait);
  digitalWrite(redLed, LOW);

  //dash dash dash
  delay (longWait);
  digitalWrite(redLed, HIGH);
  delay (longWait);
  digitalWrite(redLed, LOW);
  delay (shortWait);
  digitalWrite(redLed, HIGH);
  delay (longWait);
  digitalWrite(redLed, LOW);
  delay (shortWait);
  digitalWrite(redLed, HIGH);
  delay (longWait);
  digitalWrite(redLed, LOW);

  //dot dot dot
  delay (shortWait);
  digitalWrite(redLed, HIGH);
  delay (shortWait);
  digitalWrite(redLed, LOW);
  delay (shortWait);
  digitalWrite(redLed, HIGH);
  delay (shortWait);
  digitalWrite(redLed, LOW);
  delay (shortWait);
  digitalWrite(redLed, HIGH);
  delay (shortWait);
  digitalWrite(redLed, LOW);

  //wait between cycles
  delay (extraLongWait);
}
