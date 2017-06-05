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

load("@platformio_rules//platformio:platformio.bzl", "platformio_library")

package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "adafruit_pcd8544_interface",
    hdrs = ["adafruit_pcd8544_interface.h"],
)

cc_library(
    name = "adafruit_pcd8544_interface_mock",
    hdrs = ["adafruit_pcd8544_interface_mock.h"],
    deps = [
        ":adafruit_pcd8544_interface",
        "//external:gtest",
    ],
)

cc_test(
    name = "adafruit_pcd8544_interface_test",
    srcs = ["adafruit_pcd8544_interface_test.cc"],
    deps = [
        ":adafruit_pcd8544_interface",
        ":adafruit_pcd8544_interface_mock",
        "//external:gtest_main",
    ],
)

platformio_library(
    name = "Adafruit_PCD8544_interface",
    hdr = "adafruit_pcd8544_interface.h",
)

platformio_library(
    name = "Adafruit_PCD8544_impl",
    src = "adafruit_pcd8544_impl.cc",
    hdr = "adafruit_pcd8544_impl.h",
    deps = [
        ":Adafruit_PCD8544_interface",
        "//external:Adafruit_GFX",
        "//external:Adafruit_PCD8544",
    ],
)
