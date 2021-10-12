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

// A mock of the software serial interface.
#ifndef ARDUINO_ABSTRACTIONS_SOFTWARE_SERIAL_SOFTWARE_SERIAL_INTERFACE_MOCK_H
#define ARDUINO_ABSTRACTIONS_SOFTWARE_SERIAL_SOFTWARE_SERIAL_INTERFACE_MOCK_H

#include <stdio.h>

#include "gmock/gmock.h"
#include "software_serial_interface.h"

namespace arduino {

// Mocks the software serial interface.
class SoftwareSerialInterfaceMock : public SoftwareSerialInterface {
public:
  MOCK_METHOD1(Initialize, void(long));
  MOCK_METHOD0(BytesAvailable, int());
  MOCK_METHOD0(HadOverflow, bool());
  MOCK_METHOD1(SetTimeout, void(unsigned long));
  MOCK_METHOD1(WriteBytes, size_t(const char *));
  MOCK_METHOD2(ReadBytes, size_t(size_t, char *));
};

} // namespace arduino

#endif // ARDUINO_ABSTRACTIONS_SOFTWARE_SERIAL_SOFTWARE_SERIAL_INTERFACE_MOCK_H
