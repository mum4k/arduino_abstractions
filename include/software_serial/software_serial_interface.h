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

// A virtual interface for serial communication.
#ifndef ARDUINO_ABSTRACTIONS_SOFTWARE_SERIAL_SOFTWARE_SERIAL_INTERFACE_H
#define ARDUINO_ABSTRACTIONS_SOFTWARE_SERIAL_SOFTWARE_SERIAL_INTERFACE_H

#include <stdio.h> // for size_t

namespace arduino {

// Defines a C++ interface for serial communication with hardware modules.
class SoftwareSerialInterface {
public:
  virtual ~SoftwareSerialInterface() {}

  // Initializes the serial communication at the specified speed (baud rate).
  virtual void Initialize(long speed) = 0;

  // Get the number of bytes (characters) available for reading from a software
  // serial port. This is data that's already arrived and stored in the serial
  // receive buffer.
  virtual int BytesAvailable() = 0;

  // Tests to see if a software serial receive buffer overflow has occurred.
  // Calling this function clears the overflow flag, meaning that subsequent
  // calls will return false unless another byte of data has been received and
  // discarded in the meantime.
  virtual bool HadOverflow() = 0;

  // Sets the maximum number of milliseconds to wait while reading from the
  // serial line. Defaults to 1000.
  virtual void SetTimeout(unsigned long timeout_ms) = 0;

  // Writes the provided data to the serial line.
  // Returns 1 on success, 0 on error.
  virtual size_t WriteBytes(const char *data) = 0;

  // Reads bytes from the serial line into the provided buffer.
  // Stops if length characters was read or on a timeout set by calling
  // SetTimeout. The buffer is NOT null terminated.
  // Returns the number of characters placed into the buffer.
  virtual size_t ReadBytes(size_t length, char *buffer) = 0;
};

} // namespace arduino

#endif // ARDUINO_ABSTRACTIONS_SOFTWARE_SERIAL_SOFTWARE_SERIAL_INTERFACE_H
