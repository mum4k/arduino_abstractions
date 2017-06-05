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

// A mock of the AdafruitDhtInterface.
#ifndef ARDUINO_ABSTRACTIONS_ADAFRUIT_DHT_DHT_INTERFACE_MOCK_H
#define ARDUINO_ABSTRACTIONS_ADAFRUIT_DHT_DHT_INTERFACE_MOCK_H

#include "adafruit_dht/dht_interface.h"
#include "gmock/gmock.h"

namespace arduino {

// Mocks the Adafruit DHT interface.
class AdafruitDhtInterfaceMock : public AdafruitDhtInterface {
public:
  MOCK_METHOD2(ReadTemperature, float(TemperatureScale, ReadMode));
  MOCK_METHOD1(ReadHumidity, float(ReadMode));
};

} // namespace arduino

#endif // ARDUINO_ABSTRACTIONS_ADAFRUIT_DHT_DHT_INTERFACE_MOCK_H
