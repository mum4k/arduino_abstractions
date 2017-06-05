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

// A virtual interface that reads from the DHT sensors.
#ifndef ARDUINO_ABSTRACTIONS_ADAFRUIT_DHT_DHT_INTERFACE_H
#define ARDUINO_ABSTRACTIONS_ADAFRUIT_DHT_DHT_INTERFACE_H

namespace arduino {

// The scales to represent the temperature in.
enum TemperatureScale {
  SCALE_FAHRENHEIT,
  SCALE_CELCIUS,
};

// The temperature and humidity sensor can only be read once per two seconds.
// The read mode determines if the read requests observes this specification.
enum ReadMode {
  // The safe mode will return the last read value if the reads happen more
  // often than once per two seconds.
  READ_MODE_SAFE,

  // The forced mode reads the value from the sensor regardless of the last
  // read time.
  READ_MODE_FORCED,
};

// Defines a C++ interface for reading from the DHT sensors.
// Refer to the Adafruit DHT library for an example of use.
class AdafruitDhtInterface {
public:
  virtual ~AdafruitDhtInterface() {}

  // Reads the temperature from the DHT sensor, returning the value in the
  // requested scale.
  virtual float ReadTemperature(TemperatureScale scale, ReadMode mode) = 0;

  // Reads the humidity from the DHT sensor.
  virtual float ReadHumidity(ReadMode mode) = 0;
};

} // namespace arduino

#endif // ARDUINO_ABSTRACTIONS_ADAFRUIT_DHT_DHT_INTERFACE_H
