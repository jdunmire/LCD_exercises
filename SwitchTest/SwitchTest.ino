/* 
 * SwitchTest
 *
 * Test the switches on the LCD Breakout board. 
 *
 * SW1 => RED LED On
 * SW2 => GREEN LED On
 * SW1+SW2 => BLUE LED On
 *
 *   Requires Arduino 1.0.1 or newer due to the use of INPUT_PULLUP.
 *   Requires Bounce library from the Playground:
 *     http://playground.arduino.cc//Code/Bounce
 *
 */
#include <Bounce.h>

// Identify the connections
const int ledRed = 2;
const int ledBlue = 3;
const int ledGreen = 4;

const int buttonSW1 = 5;
const int buttonSW2 = 6;

// Identify LED states
const int ledOFF = HIGH;
const int ledON = LOW;

// Switch states
const uint8_t SWPressed = LOW;
const uint8_t SWReleased = HIGH;

// Set options
const unsigned long interval_ms = 5;

// debounced switches
Bounce sw1 = Bounce(buttonSW1, interval_ms);
Bounce sw2 = Bounce(buttonSW2, interval_ms);

void setup() {
  // Use Arduino's built-in pullups rather than external resistors.
  pinMode(buttonSW1, INPUT_PULLUP);
  pinMode(buttonSW2, INPUT_PULLUP);

  // Assume the switches are not pressed when the sketch starts
  sw1.write(SWReleased);
  sw2.write(SWReleased);

  // turn the leds off and then set the pins as outputs so that
  // there is no pulse during startup.
  digitalWrite(ledRed, ledOFF);
  digitalWrite(ledBlue, ledOFF);
  digitalWrite(ledGreen, ledOFF);
  pinMode(ledRed, OUTPUT);     
  pinMode(ledBlue, OUTPUT);     
  pinMode(ledGreen, OUTPUT);     
}

void loop() {
  sw1.update();
  sw2.update();

  if ((sw1.read() == SWPressed) && (sw2.read() == SWPressed))
  {
    digitalWrite(ledRed, ledOFF);
    digitalWrite(ledGreen, ledOFF);
    digitalWrite(ledBlue, ledON);
  } 
  else if (sw1.read() == SWPressed)
  {
    digitalWrite(ledRed, ledON);
    digitalWrite(ledGreen, ledOFF);
    digitalWrite(ledBlue, ledOFF);
  } 
  else if (sw2.read() == SWPressed)
  {
    digitalWrite(ledRed, ledOFF);
    digitalWrite(ledGreen, ledON);
    digitalWrite(ledBlue, ledOFF);
  } 
  else
  {
    digitalWrite(ledRed, ledOFF);
    digitalWrite(ledGreen, ledOFF);
    digitalWrite(ledBlue, ledOFF);
  } 

}

