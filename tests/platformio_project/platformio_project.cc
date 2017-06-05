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

// Project that just imports and compiles the virtual interfaces and their
// Arduino implementations.
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Adafruit_PCD8544_impl.h>
#include <Adafruit_PCD8544_interface.h>
#include <Arduino.h>
#include <Arduino_impl.h>
#include <Arduino_interface.h>
#include <DHT.h>
#include <DHT_impl.h>
#include <DHT_interface.h>
#include <Software_serial_impl.h>
#include <Software_serial_interface.h>

using arduino::ArduinoImpl;
using arduino::ArduinoInterface;
using arduino::AdafruitPcd8544Impl;
using arduino::AdafruitPcd8544Interface;
using arduino::AdafruitDhtInterface;
using arduino::AdafruitDhtImpl;
using arduino::SoftwareSerialInterface;
using arduino::SoftwareSerialImpl;

// Arduino hardware layer.
const ArduinoImpl ino = ArduinoImpl();

// A Nokia PCD8544 display via the software SPI.
// Pinout:
//   pin 45 - Serial clock out (SCLK)
//   pin 47 - Serial data out (DIN)
//   pin 49 - Data/Command select (D/C)
//   pin 51 - LCD chip select (CS)
//   pin 53 - LCD reset (RST)
Adafruit_PCD8544 pcd8544 = Adafruit_PCD8544(45, 47, 49, 51, 53);

// The PCD8544 display.
AdafruitPcd8544Impl display = AdafruitPcd8544Impl(&pcd8544);

// The DHT sensor.
AdafruitDhtImpl sensor = AdafruitDhtImpl(54, arduino::SENSOR_DHT22);

// A software serial interface.
SoftwareSerialImpl serial(/* rx = */ 9, /* tx = */ 8);

// A compile time check that the implementations comply to the interfaces.
void VerifyInterfaceCompliance(const ArduinoInterface &ino,
                               AdafruitPcd8544Interface *display,
                               AdafruitDhtInterface *dht,
                               SoftwareSerialInterface *serial) {}

void setup() { VerifyInterfaceCompliance(ino, &display, &sensor, &serial); }

void loop() {}
