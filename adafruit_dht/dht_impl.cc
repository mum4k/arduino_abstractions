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

#include <DHT_impl.h>

#include <stdint.h>

#include <DHT.h>

namespace arduino {
namespace {

// Converts the temperature scale enum to a bool based on the API definition of
// the Adafruit DHT library.
bool ScaleToBool(TemperatureScale scale) { return scale == SCALE_FAHRENHEIT; }

// Converts the read mode enum to a bool based on the API definition of
// the Adafruit DHT library.
bool ModeToBool(ReadMode mode) { return mode == READ_MODE_FORCED; }

} // namespace

AdafruitDhtImpl::AdafruitDhtImpl(uint8_t pin, SensorType type)
    : dht_(pin, uint8_t(type)) {}

AdafruitDhtImpl::~AdafruitDhtImpl() {}

float AdafruitDhtImpl::ReadTemperature(TemperatureScale scale, ReadMode mode) {
  return dht_.readTemperature(ScaleToBool(scale), ModeToBool(mode));
}

float AdafruitDhtImpl::ReadHumidity(ReadMode mode) {
  return dht_.readHumidity(ModeToBool(mode));
}

} // namespace arduino
