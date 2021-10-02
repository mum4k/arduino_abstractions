/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include "arduino/arduino_impl.h"

// Arduino hardware layer.
arduino::ArduinoImpl ino;

// Turns on the provided pin number.
void WriteHighToPin(const arduino::ArduinoInterface &ino, uint8_t pin_number) {
  ino.DigitalWrite(pin_number, 1);
}

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

// cppcheck-suppress unusedFunction
void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// cppcheck-suppress unusedFunction
void loop()
{
  // turn the LED on (HIGH is the voltage level)
  // digitalWrite(LED_BUILTIN, HIGH);
  WriteHighToPin(ino, LED_BUILTIN);
  // wait for a second
  delay(1000);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);

   // wait for a second
  delay(1000);
}