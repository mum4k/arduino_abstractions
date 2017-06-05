/*
 * Copyright 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// A virtual interface that controls PCD8544 displays.
#ifndef ARDUINO_ABSTRACTIONS_ADAFRUIT_PCD8544_ADAFRUIT_PCD8544_INTERFACE_H
#define ARDUINO_ABSTRACTIONS_ADAFRUIT_PCD8544_ADAFRUIT_PCD8544_INTERFACE_H

#include <stdint.h>
#include <stdio.h>

namespace arduino {

// The decimal base ten.
const int kBaseTen = 10;

// The default display contrast for a call to AdafruitPcd8544Interface::begin().
const uint8_t kDefaultContrast = 60;

// The default display bias for a call to AdafruitPcd8544Interface::begin().
const uint8_t kDefaultBias = 0x04;

// Defines a C++ interface for controlling the PCD8544 displays.
// Refer to the Adafruit PCD8544 library for an example of use.
class AdafruitPcd8544Interface {
public:
  virtual ~AdafruitPcd8544Interface() {}

  // Initializes the display.
  virtual void Begin(uint8_t contrast, uint8_t bias) = 0;

  // Clears the display.
  virtual void ClearDisplay(void) = 0;

  // Sets the desired contrast.
  virtual void SetContrast(uint8_t value) = 0;

  // Sets the size of the text on the display.
  virtual void SetTextSize(uint8_t size) = 0;

  // Sets the text color.
  virtual void SetTextColor(uint16_t color) = 0;

  // Sets the cursor position.
  virtual void SetCursor(int16_t x, int16_t y) = 0;

  // Print functions as defined in Print.h.
  virtual size_t Print(int number, int base) = 0;
  virtual size_t Print(unsigned int number, int base) = 0;
  virtual size_t Print(long number, int base) = 0;
  virtual size_t Print(unsigned long number, int base) = 0;
  virtual size_t Print(double number, int digits) = 0;
  virtual size_t Print(const char characters[]) = 0;

  // Println functions as defined in Print.h.
  virtual size_t Println(int number, int base) = 0;
  virtual size_t Println(unsigned int number, int base) = 0;
  virtual size_t Println(long number, int base) = 0;
  virtual size_t Println(unsigned long number, int base) = 0;
  virtual size_t Println(double number, int digits) = 0;
  virtual size_t Println(const char characters[]) = 0;

  // Actually displays something on the display. This must be called after any
  // methods that draw objects or print text like print or println.
  virtual void Display() = 0;
};

} // namespace arduino

#endif // ARDUINO_ABSTRACTIONS_ADAFRUIT_PCD8544_ADAFRUIT_PCD8544_INTERFACE_H
