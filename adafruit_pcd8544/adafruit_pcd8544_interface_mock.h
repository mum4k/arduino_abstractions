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

// A mock of the AdafruitPcd8544Interface.
#ifndef ARDUINO_ABSTRACTIONS_ADAFRUIT_PCD8544_ADAFRUIT_PCD8544_INTERFACE_MOCK_H
#define ARDUINO_ABSTRACTIONS_ADAFRUIT_PCD8544_ADAFRUIT_PCD8544_INTERFACE_MOCK_H

#include <stdint.h>
#include <stdio.h>

#include "adafruit_pcd8544/adafruit_pcd8544_interface.h"
#include "gmock/gmock.h"

namespace arduino {

// Mocks the Adafruit PCD8544 interface.
class AdafruitPcd8544InterfaceMock : public AdafruitPcd8544Interface {
public:
  MOCK_METHOD2(Begin, void(uint8_t, uint8_t));
  MOCK_METHOD0(ClearDisplay, void());
  MOCK_METHOD1(SetContrast, void(uint8_t));
  MOCK_METHOD1(SetTextSize, void(uint8_t));
  MOCK_METHOD1(SetTextColor, void(uint16_t));
  MOCK_METHOD2(SetCursor, void(int16_t, int16_t));
  MOCK_METHOD2(Print, size_t(int, int));
  MOCK_METHOD2(Print, size_t(unsigned int, int));
  MOCK_METHOD2(Print, size_t(long, int));
  MOCK_METHOD2(Print, size_t(unsigned long, int));
  MOCK_METHOD2(Print, size_t(double, int));
  MOCK_METHOD1(Print, size_t(const char[]));
  MOCK_METHOD2(Println, size_t(int, int));
  MOCK_METHOD2(Println, size_t(unsigned int, int));
  MOCK_METHOD2(Println, size_t(long, int));
  MOCK_METHOD2(Println, size_t(unsigned long, int));
  MOCK_METHOD2(Println, size_t(double, int));
  MOCK_METHOD1(Println, size_t(const char[]));
  MOCK_METHOD0(Display, void());
};

} // namespace arduino

#endif // ARDUINO_ABSTRACTIONS_ADAFRUIT_PCD8544_ADAFRUIT_PCD8544_INTERFACE_MOCK_H
