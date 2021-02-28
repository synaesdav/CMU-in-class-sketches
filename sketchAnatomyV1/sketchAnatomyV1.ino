//This is an outline of the parts of a sketch
//written by David Crittenden 1/2021
//writen for Circuit Playground Classic 32u4
//uses code derived from Adafruit's NeoPixel strand test

//Use double forward slashes to make a single line comment.

/*
   Use a single forward slash and asterisk to start a block of comments.
   Usefull when adding large descpiptive text.
   Use the asterisk and single forward slash to end the block of comments.
*/

//Use comments here to explain what the code is, what board it was designed for, etc...
//Use comments to site sources of where you found code to give credit and retain context.
//Use comments throughout the code to explain functionality, label variables, make life easier for future you.

//Add libraries for interfacing with different hardwear or functionality.
#include"otherTabs.h"//Use quotations to add code from other tabs in this sketch.
#include <Adafruit_NeoPixel.h> //Use < > to add libraries from your libraries folder.

//Define values for variables that will not change in the sketch. (like pin numbers or number of pixels in a strand)
#define PIN 17//Creates a variable called PIN that contains value 17. (I am using pin 17 for the Circuit Playground's onboard NeoPixels)
#define N_Pixels 10//Creates a variable called N_Pixels that contains the value 10 (number of NeoPixels in my string)

//Create any objects needed. (like declaring the NeoPixel string)
//Note the use of the variables that you just defined
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_Pixels, PIN, NEO_GRB + NEO_KHZ800);
//Creates an object of class Adafruit_NeoPixel called strip with the parameters:
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags (check product data sheet if unsure), add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

//Declare any global variables to be used by the whole sketch.
//Starting values may or may not be defined.
//Using variables here allows you to easily change values without hunting down numbers within the code.
uint8_t i;//Declares an unsigned 8 bit global variable named i with no value defined.
uint16_t j;//Declares an unsigned 16 bit global variable named j with no value defined.
int myVariable = 287;//Declares an integer global variable named myVariable with a starting value of 287.
bool isItTrue = false;//Declares a boolean global variable named isItTrue with a starting value of 0.
float calibrateThis = 0.021;//Declares a floating point global variable named calibrateThis with a starting value of 0.021.


void setup()
{
  //Every command in setup will be executed once.
  
  //Initialize objects (like the NeoPixel string or the serial monitor)
  strip.begin();//Initialize the NeoPixel strip object. (REQUIRED)
  strip.show();//Turn off all pixels.
  
  //Set the brightness of NeoPixels.
  strip.setBrightness(50); //Set BRIGHTNESS to about 1/5 (max = 255)
  
  //Set the baud rate if using serial.
  //Finish any needed configuration of hardwear.
  //Any series of commands to be executed once.
}

void loop()
{
  //Every command here will be executed in order on an endless loop.
  //This is the main part of the sketch.
}

void otherFunctions()//functions you write that get called from the main loop
{
  //You can declare variables here that only get used by this function.
  //Functions are usefull in repetitve tasks.
  //You can pass values to a function to be manipulated and return values to the main loop.
  //You can call a function from within another function.
}
