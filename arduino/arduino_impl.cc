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

#include <Arduino_impl.h>

#include <Arduino.h>
#include <Arduino_interface.h>

namespace arduino {

ArduinoImpl::~ArduinoImpl() {}

int ArduinoImpl::DigitalRead(uint8_t pin) const { return digitalRead(pin); }

void ArduinoImpl::DigitalWrite(uint8_t pin, uint8_t value) const {
  return digitalWrite(pin, value);
}

int ArduinoImpl::AnalogRead(uint8_t pin) const { return analogRead(pin); }

void ArduinoImpl::AnalogWrite(uint8_t pin, uint8_t value) const {
  return analogWrite(pin, value);
}

void ArduinoImpl::PinMode(uint8_t pin, uint8_t mode) const {
  return pinMode(pin, mode);
}

unsigned long ArduinoImpl::Millis(void) const { return millis(); }

void ArduinoImpl::Delay(unsigned long ms) const { delay(ms); }

} // namespace arduino
