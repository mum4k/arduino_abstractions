# Google testing and mocking framework for C++.
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
    name = "com_google_googletest",
    urls = ["https://github.com/google/googletest/archive/release-1.8.1.zip"],
    strip_prefix = "googletest-release-1.8.1",
    sha256 = "927827c183d01734cc5cfef85e0ff3f5a92ffe6188e0d18e909c5efebf28a0c7",
)

# Bazel's native git support (via the command line git command).
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

# PlatformIO Bazel rules.
git_repository(
    name = "platformio_rules",
    remote = "https://github.com/mum4k/platformio_rules.git",
    tag = "v0.0.3",
)

# Adafruit: Unified Sensor Driver.
new_git_repository(
    name = "com_github_Adafruit_Sensor",
    remote = "https://github.com/adafruit/Adafruit_Sensor.git",
    tag = "1.0.2",
    build_file_content = """
load("@platformio_rules//platformio:platformio.bzl", "platformio_library")

platformio_library(
    name = "Adafruit_Sensor",
    hdr = "Adafruit_Sensor.h",
    visibility = ["//visibility:public"],
)
"""
)

bind(
    name = "Adafruit_Sensor",
    actual = "@com_github_Adafruit_Sensor//:Adafruit_Sensor",
)

# Adafruit: Library for DHT11DHT22, etc Temp & Humidity Sensors.
new_git_repository(
    name = "com_github_Adafruit_DHT",
    remote = "https://github.com/adafruit/DHT-sensor-library.git",
    tag = "1.3.1",
    build_file_content = """
load("@platformio_rules//platformio:platformio.bzl", "platformio_library")

platformio_library(
    name = "DHT",
    src = "DHT.cpp",
    add_hdrs = [
        "DHT_U.h",
    ],
    add_srcs = [
        "DHT_U.cpp",
    ],
    hdr = "DHT.h",
    visibility = ["//visibility:public"],
    deps = [
        "//external:Adafruit_Sensor",
    ],
)
"""
)

bind(
    name = "DHT",
    actual = "@com_github_Adafruit_DHT//:DHT",
)

# Adafruit: Nokia 5110 LCD Library.
new_git_repository(
    name = "com_github_Adafruit_PCD8544",
    remote = "https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library.git",
    tag = "1.0.0",
    build_file_content = """
load("@platformio_rules//platformio:platformio.bzl", "platformio_library")

platformio_library(
    name = "Adafruit_PCD8544",
    src = "Adafruit_PCD8544.cpp",
    hdr = "Adafruit_PCD8544.h",
    visibility = ["//visibility:public"],
    deps = [
        "//external:Adafruit_GFX",
    ],
)
"""
)

bind(
    name = "Adafruit_PCD8544",
    actual = "@com_github_Adafruit_PCD8544//:Adafruit_PCD8544",
)

# Adafruit: Adafruit core GFX library.
new_git_repository(
    name = "com_github_Adafruit_GFX",
    remote = "https://github.com/adafruit/Adafruit-GFX-Library.git",
    tag = "1.3.6",
    build_file_content = """
load("@platformio_rules//platformio:platformio.bzl", "platformio_library")

platformio_library(
    name = "Adafruit_GFX",
    src = "Adafruit_GFX.cpp",
    add_hdrs = glob([
        "gfxfont.h",
        "Fonts/*.h",
    ]),
    add_srcs = [
        "glcdfont.c",
    ],
    hdr = "Adafruit_GFX.h",
    visibility = ["//visibility:public"],
)
"""
)

bind(
    name = "Adafruit_GFX",
    actual = "@com_github_Adafruit_GFX//:Adafruit_GFX",
)
