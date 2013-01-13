/*
 * gLCD_test - Check configuration for SparkFun Color LCD Breakout
 *
 * Verify setup for use with gLCD-Library by drawing squares at
 * different distances from the edge of the display.
 *
 * Requires gLCD library from https://github.com/TCWORLD/gLCD-Library
 * Tested with gLCD version 3.4
 */
#include <gLCD.h>

// allocate pins for each function
const char RST = 8;
const char CS = 9;
const char Clk = 13;
const char Data = 11;

gLCD graphic(RST, CS, Clk, Data, HIGH_SPEED);

// Screen offset and size
// - Adjust Xoffset/Yoffset until boxes start in the top left corner of
//   the screen
//
// - Then if blue is visible outside the Red box, adjust the Xmax,Ymax
//   values.
//
// Repeat until all four edges of the Red box are visible and there is
// no blue showing outside the Red box.
const int Xoffset = 2;
const int Yoffset = 0;
const int Xmax = 129;
const int Ymax = 129;

void setup() {
  // See gLCD/examples/BasicFunctions.pde for driver options
  // (EPSON/PHILLIPS)
  //
  // Set the rotation based on the LCD 'tab' location:
  //    Top: ROTATION_0
  // Bottom: ROTATION_180
  //  Right: ROTATION_90
  //   Left: ROTATION_270
  graphic.begin(Xoffset, Yoffset, 0, EPSON, ROTATION_180);

  // Draw boxes around the edge of the screen
  graphic.setForeColour(15, 0, 0);   // Red
  graphic.Box(0, 0, Xmax, Ymax,6);

  graphic.setForeColour(15, 15, 15); // White
  graphic.Box(1, 1, Xmax-1, Ymax-1, 6);

  graphic.setForeColour(0, 15, 0);   // Green
  graphic.Box(2, 2, Xmax-2, Ymax-2, 6);

  graphic.setForeColour(15, 15, 15); // White
  graphic.Box(3, 3, Xmax-3, Ymax-3, 6);

  // Write a welcome message at the center of the screen
  graphic.setForeColour(0,15,0);
  graphic.setBackColour(15,0,0);
  graphic.setFont(Normal_SolidBG);
  graphic.setCoordinate(Xmax/2, Ymax/2);
  graphic.print("Hello");

  // Mark the center of the screen
  graphic.setForeColour(15,15,15);
  graphic.Line(0, 0, Xmax, Ymax, SolidForeColour);
  graphic.Line(0, Ymax, Xmax, 0, SolidForeColour);

}


void loop() {
  // Nothing to do
  while(1)
  {
    delay(1000);
  }
}


/* vim: set ts=8 sw=2 tw=76 wm=4 et :*/
