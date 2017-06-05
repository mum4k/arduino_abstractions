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

#include <Software_serial_impl.h>

#include <stdint.h>
#include <stdio.h>

#include <SoftwareSerial.h>

namespace arduino {

SoftwareSerialImpl::SoftwareSerialImpl(uint8_t receive_pin,
                                       uint8_t transmit_pin,
                                       bool inverse_logic = false)
    : serial_(receive_pin, transmit_pin, inverse_logic) {}

SoftwareSerialImpl::~SoftwareSerialImpl() {}

void SoftwareSerialImpl::Initialize(long speed) { serial_.begin(speed); }

int SoftwareSerialImpl::BytesAvailable() { return serial_.available(); }

bool SoftwareSerialImpl::HadOverflow() { return serial_.overflow(); }

void SoftwareSerialImpl::SetTimeout(unsigned long timeout_ms) {
  serial_.setTimeout(timeout_ms);
}

size_t SoftwareSerialImpl::WriteBytes(const char *data) {
  return serial_.write(data);
}

size_t SoftwareSerialImpl::ReadBytes(size_t length, char *buffer) {
  return serial_.readBytes(buffer, length);
}

} // namespace arduino
