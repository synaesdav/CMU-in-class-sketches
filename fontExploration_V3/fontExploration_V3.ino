//sketch to explore custom bitmap development
//counts 0 - 9 to test bitmap appearance
//requires the creation of bitmaps for each character
//put BitmapData.h text into another tab 

//uses a switch case statement to display each bitmap
//using bitmap creation as explained at https://learn.adafruit.com/steampunk-cameo-necklace

//written for Arduino Uno and a NeoPixel Shield by David Crittenden 2/21

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

#include <Adafruit_GFX.h>//graphics library
#include <Adafruit_NeoMatrix.h>//matrix library
#include <Adafruit_NeoPixel.h>//NeoPixel library

#include "bitmapData.h"//stores bitmap data in other tab
#include <avr/pgmspace.h> //stores the bitmaps in program memory

int PIN = 6;//NeoPixels are on pin 6

//matrix for Noelle:
/*Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(17, 5, PIN,
                            NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                            NEO_GRB            + NEO_KHZ800);*/

//my test matrix arduino sheild:
Adafruit_NeoMatrix matrix(8, 5, PIN,
                          NEO_MATRIX_TOP      + NEO_MATRIX_LEFT +
                          NEO_MATRIX_ROWS     + NEO_MATRIX_PROGRESSIVE,
                          NEO_GRB             + NEO_KHZ800);

int wait = 1000;//amount to wait between number counting

void setup()
{
  Serial.begin(9600);
  matrix.begin();
  matrix.setBrightness(50);
  matrix.show();
}

void loop()
{
  for (int i = 0; i < 10; i++)
  {
    switch (i)
    {
      case 0:
        matrix.drawBitmap(0, 0, zero, 4, 5, (matrix.Color(255, 0, 0)));
        break;

      case 1:
        matrix.drawBitmap(0, 0, one, 4, 5, (matrix.Color(255, 0, 0)));
        break;

      case 2:
        matrix.drawBitmap(0, 0, two, 4, 5, (matrix.Color(255, 0, 0)));
        break;

      case 3:
        matrix.drawBitmap(0, 0, three, 4, 5, (matrix.Color(255, 0, 0)));
        break;

      case 4:
        matrix.drawBitmap(0, 0, four, 4, 5, (matrix.Color(255, 0, 0)));
        break;

      case 5:
        matrix.drawBitmap(0, 0, five, 4, 5, (matrix.Color(255, 0, 0)));
        break;

      case 6:
        matrix.drawBitmap(0, 0, six, 4, 5, (matrix.Color(255, 0, 0)));
        break;

      case 7:
        matrix.drawBitmap(0, 0, seven, 4, 5, (matrix.Color(255, 0, 0)));
        break;

      case 8:
        matrix.drawBitmap(0, 0, eight, 4, 5, (matrix.Color(255, 0, 0)));
        break;

      case 9:
        matrix.drawBitmap(0, 0, nine, 4, 5, (matrix.Color(255, 0, 0)));
        break;
    }
    matrix.show();
    Serial.println(i);
    delay(wait);
    matrix.clear();//black out all the pixels
    matrix.show();
  }
}
