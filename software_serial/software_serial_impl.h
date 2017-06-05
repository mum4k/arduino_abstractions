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

// Implementation of the Software Serial interface that uses the real Arduino
// hardware.
#ifndef ARDUINO_ABSTRACTIONS_SOFTWARE_SERIAL_SOFTWARE_SERIAL_IMPL_H
#define ARDUINO_ABSTRACTIONS_SOFTWARE_SERIAL_SOFTWARE_SERIAL_IMPL_H

#include <stdint.h>
#include <stdio.h>

#include <SoftwareSerial.h>
#include <Software_serial_interface.h>

namespace arduino {

// Implements the Software Serial Interface using the real Arduino hardware
// layer.
class SoftwareSerialImpl : public SoftwareSerialInterface {
public:
  // The receive_pin is the pin on which to receive serial data, the
  // transmit_pin is the pin on which to transmit serial data.
  // The parameter inverse_logic is used to invert the sense of incoming bits
  // (the default is normal logic). If set, SoftwareSerialImpl treats a LOW (0
  // volts on the pin, normally) on the Rx pin as a 1-bit (the idle state) and a
  // HIGH (5 volts on the pin, normally) as a 0-bit. It also affects the way
  // that it writes to the Tx pin. Default value is false.
  SoftwareSerialImpl(uint8_t receive_pin, uint8_t transmit_pin,
                     bool inverse_logic = false);
  ~SoftwareSerialImpl() override;

  void Initialize(long speed) override;
  int BytesAvailable() override;
  bool HadOverflow() override;
  void SetTimeout(unsigned long timeout_ms) override;
  size_t WriteBytes(const char *data) override;
  size_t ReadBytes(size_t length, char *buffer) override;

private:
  // The SoftwareSerial instance used to communicate over the serial line.
  SoftwareSerial serial_;
};

} // namespace arduino

#endif // ARDUINO_ABSTRACTIONS_SOFTWARE_SERIAL_SOFTWARE_SERIAL_IMPL_H
