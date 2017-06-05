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
    name = "software_serial_interface",
    hdrs = ["software_serial_interface.h"],
)

cc_library(
    name = "software_serial_interface_mock",
    hdrs = ["software_serial_interface_mock.h"],
    deps = [
        ":software_serial_interface",
        "//external:gtest",
    ],
)

cc_test(
    name = "software_serial_interface_test",
    srcs = ["software_serial_interface_test.cc"],
    deps = [
        ":software_serial_interface",
        ":software_serial_interface_mock",
        "//external:gtest_main",
    ],
)

platformio_library(
    name = "Software_serial_interface",
    hdr = "software_serial_interface.h",
)

platformio_library(
    name = "Software_serial_impl",
    src = "software_serial_impl.cc",
    hdr = "software_serial_impl.h",
    deps = [":Software_serial_interface"],
)
