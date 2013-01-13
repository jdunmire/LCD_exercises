/*
 * LED Blink
 * Turns the RGB LEDs on the LCD Breakout board on/off.
 */
 
// Identify the LED connections
int ledRed = 2;   // RED
int ledBlue = 3;  // BLUE
int ledGreen = 4;  // GREEN
int ledOFF=HIGH;
int ledON=LOW;

// the setup routine runs once when you press reset:
void setup() {                
  // turn the leds off and then set the pins as outputs so that
  // there is no pulse during startup.
  digitalWrite(ledRed, ledOFF);
  digitalWrite(ledBlue, ledOFF);
  digitalWrite(ledGreen, ledOFF);
  pinMode(ledRed, OUTPUT);     
  pinMode(ledBlue, OUTPUT);     
  pinMode(ledGreen, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(ledRed, ledON);
  delay(1000);               // wait for a second
  digitalWrite(ledRed, ledOFF);
  digitalWrite(ledBlue, ledON);
  delay(1000);               // wait for a second
  digitalWrite(ledBlue, ledOFF);
  digitalWrite(ledGreen, ledON);
  delay(1000);               // wait for a second
  digitalWrite(ledGreen, ledOFF);
}
