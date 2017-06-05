# Copyright 2017 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

load("@platformio_rules//platformio:platformio.bzl", "platformio_project")

# PlatformIO project used to verify that the provided interfaces and
# implementations compile using avr-gcc.
platformio_project(
    name = "platformio_project",
    src = "platformio_project.cc",
    board = "megaatmega2560",
    framework = "arduino",
    platform = "atmelavr",
    deps = [
        "//adafruit_dht:DHT_impl",
        "//adafruit_dht:DHT_interface",
        "//adafruit_pcd8544:Adafruit_PCD8544_impl",
        "//adafruit_pcd8544:Adafruit_PCD8544_interface",
        "//arduino:Arduino_impl",
        "//arduino:Arduino_interface",
        "//external:Adafruit_GFX",
        "//external:Adafruit_PCD8544",
        "//external:DHT",
        "//software_serial:Software_serial_impl",
        "//software_serial:Software_serial_interface",
    ],
)
