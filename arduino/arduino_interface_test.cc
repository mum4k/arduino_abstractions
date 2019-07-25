// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "arduino/arduino_interface.h"

#include <stdint.h>

#include "arduino/arduino_interface_mock.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::Return;

namespace arduino {
namespace {

const uint8_t kOn = 1;
const uint8_t kAnalog = 120;
const uint8_t kPinNumber = 13;

// Turns on the provided pin number.
void WriteHighToPin(const arduino::ArduinoInterface &ino, uint8_t pin_number) {
  ino.DigitalWrite(pin_number, kOn);
}

// Reads digital value from the provided pin.
int ReadFromPin(const arduino::ArduinoInterface &ino, uint8_t pin_number) {
  return ino.DigitalRead(pin_number);
}

// Assigns analog value to provided pin.
void WriteAnalogToPin(const arduino::ArduinoInterface &ino, uint8_t pin_number, uint8_t value) {
  ino.AnalogWrite(pin_number, 120);
}

// Reads analog value from the provided pin.
int ReadAnalogFromPin(const arduino::ArduinoInterface &ino, uint8_t pin_number) {
  return ino.AnalogRead(pin_number);
}

// Sets the provided pin to accept INPUT
void SetPinModeInput(const arduino::ArduinoInterface &ino, uint8_t pin_number) {
  ino.PinMode(pin_number, 0);
}

// Sleeps for the provided amount of milliseconds and returns the number of
// milliseconds since startup.
unsigned long DelayAndGetMillis(const arduino::ArduinoInterface &ino,
                                unsigned long sleep_ms) {
  ino.Delay(sleep_ms);
  return ino.Millis();
}

class ArduinoInterfaceTest : public ::testing::Test {
protected:
  ArduinoInterfaceTest() {}

  const ArduinoInterfaceMock mock_;
};

TEST_F(ArduinoInterfaceTest, MocksDigitalWrite) {
  EXPECT_CALL(mock_, DigitalWrite(kPinNumber, kOn));
  WriteHighToPin(mock_, kPinNumber);
}

TEST_F(ArduinoInterfaceTest, MocksDigitalRead) {
  const int expected = 42;
  EXPECT_CALL(mock_, DigitalRead(kPinNumber)).WillOnce(Return(expected));
  EXPECT_EQ(expected, ReadFromPin(mock_, kPinNumber));
}

TEST_F(ArduinoInterfaceTest, MocksAnalogWrite) {
  EXPECT_CALL(mock_, AnalogWrite(kPinNumber, kAnalog));
  WriteHighToPin(mock_, kPinNumber);
}

TEST_F(ArduinoInterfaceTest, MocksAnalogRead) {
  const int expected = 42;
  EXPECT_CALL(mock_, AnalogRead(kPinNumber)).WillOnce(Return(expected));
  EXPECT_EQ(expected, ReadFromPin(mock_, kPinNumber));
}

TEST_F(ArduinoInterfaceTest, MocksPinMode) {
  EXPECT_CALL(mock_, PinMode(kPinNumber, kOn));
  SetPinModeInput(mock_, kPinNumber);
}

TEST_F(ArduinoInterfaceTest, MocksDelayAndMillis) {
  const unsigned long sleep_ms = 2;
  EXPECT_CALL(mock_, Delay(sleep_ms));
  const int expected = 42;
  EXPECT_CALL(mock_, Millis()).WillOnce(Return(expected));
  EXPECT_EQ(expected, DelayAndGetMillis(mock_, sleep_ms));
}

} // namespace
} // namespace arduino
