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

// Implementation of the AdafruitPcd8544Interface uses the real display.
#ifndef ARDUINO_ABSTRACTIONS_ADAFRUIT_PCD8544_ADAFRUIT_PCD8544_IMPL_H
#define ARDUINO_ABSTRACTIONS_ADAFRUIT_PCD8544_ADAFRUIT_PCD8544_IMPL_H

#include <stdint.h>
#include <stdio.h>

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Adafruit_PCD8544_interface.h>

namespace arduino {

// Implements the Adafruit PCD8544 interface using the real display.
class AdafruitPcd8544Impl : public AdafruitPcd8544Interface {
public:
  // Constructs the Adafruit PCD8544 implementation.
  // The display instance must not be null and isn't owned.
  explicit AdafruitPcd8544Impl(Adafruit_PCD8544 *display);
  ~AdafruitPcd8544Impl() override;

  virtual void Begin(uint8_t contrast, uint8_t bias) override;
  virtual void ClearDisplay(void) override;
  virtual void SetContrast(uint8_t value) override;
  virtual void SetTextSize(uint8_t size) override;
  virtual void SetTextColor(uint16_t color) override;
  virtual void SetCursor(int16_t x, int16_t y) override;
  virtual size_t Print(int number, int base) override;
  virtual size_t Print(unsigned int number, int base) override;
  virtual size_t Print(long number, int base) override;
  virtual size_t Print(unsigned long number, int base) override;
  virtual size_t Print(double number, int digits) override;
  virtual size_t Print(const char characters[]) override;
  virtual size_t Println(int number, int base) override;
  virtual size_t Println(unsigned int number, int base) override;
  virtual size_t Println(long number, int base) override;
  virtual size_t Println(unsigned long number, int base) override;
  virtual size_t Println(double number, int digits) override;
  virtual size_t Println(const char characters[]) override;
  virtual void Display() override;

private:
  // Instance of the Adafruit PCD8544 class.
  Adafruit_PCD8544 *display_;
};

} // namespace arduino

#endif // ARDUINO_ABSTRACTIONS_ADAFRUIT_PCD8544_ADAFRUIT_PCD8544_IMPL_H
