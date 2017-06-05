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

// Implementation of the AdafruitDhtInterface that uses the real sensor.
#ifndef ARDUINO_ABSTRACTIONS_ADAFRUIT_DHT_DHT_IMPL_H
#define ARDUINO_ABSTRACTIONS_ADAFRUIT_DHT_DHT_IMPL_H

#include <stdint.h>

#include <DHT.h>
#include <DHT_interface.h>

namespace arduino {

// The supported sensor types.
enum SensorType {
  SENSOR_DHT11 = 11,
  SENSOR_DHT22 = 22,
  SENSOR_DHT21 = 21,
  SENSOR_AM2301 = 21,
};

// Implements the Adafruit DHT interface using the real sensor.
class AdafruitDhtImpl : public AdafruitDhtInterface {
public:
  // Constructs the Adafruit DHT implementation.
  // The pin number is the number of the digital pin where the sensor's data
  // line is connected.
  AdafruitDhtImpl(uint8_t pin, SensorType type);
  ~AdafruitDhtImpl() override;

  float ReadTemperature(TemperatureScale scale, ReadMode mode) override;
  float ReadHumidity(ReadMode mode) override;

private:
  // Instance of the Adafruit DHT class.
  DHT dht_;
};

} // namespace arduino

#endif // ARDUINO_ABSTRACTIONS_ADAFRUIT_DHT_DHT_IMPL_H
