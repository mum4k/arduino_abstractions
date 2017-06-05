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

#include "adafruit_dht/dht_interface.h"

#include <stdint.h>

#include "adafruit_dht/dht_interface_mock.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::Return;

namespace arduino {
namespace {

float CallReadTemperature(AdafruitDhtInterface *sensor, TemperatureScale scale,
                          ReadMode mode) {
  return sensor->ReadTemperature(scale, mode);
}

float CallReadHumidity(AdafruitDhtInterface *sensor, ReadMode mode) {
  return sensor->ReadHumidity(mode);
}

class AdafruitDhtInterfaceTest : public ::testing::Test {
protected:
  AdafruitDhtInterfaceTest() {}

  AdafruitDhtInterfaceMock mock_;
};

TEST_F(AdafruitDhtInterfaceTest, MocksReadTemperature) {
  TemperatureScale scale = SCALE_CELCIUS;
  ReadMode mode = READ_MODE_SAFE;
  const float expected = 20.0;
  EXPECT_CALL(mock_, ReadTemperature(scale, mode)).WillOnce(Return(expected));
  EXPECT_EQ(expected, CallReadTemperature(&mock_, scale, mode));
}

TEST_F(AdafruitDhtInterfaceTest, MocksReadHumidity) {
  ReadMode mode = READ_MODE_SAFE;
  const float expected = 90.0;
  EXPECT_CALL(mock_, ReadHumidity(mode)).WillOnce(Return(expected));
  EXPECT_EQ(expected, CallReadHumidity(&mock_, mode));
}

} // namespace
} // namespace arduino
