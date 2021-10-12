# Arduino abstractions for unit tests

A collection of virtual interfaces and
[googletest](https://github.com/google/googletest) mocks for Arduino that
replace libraries directly interacting with the hardware.

These can be used as arguments for classes and functions allowing the author to
write native c++ unit tests using the dependancy injection pattern.

## Disclaimer

This is not an official Google product.

## Prerequisites

This document assumes that you know how to write unit tests using the
**googletest** library and how to use the mocks and write mock expectations via
the **googlemock** library. If you need the refresher, see the following
documents:

*   [Introduction to Google C++ Testing
    Framework](https://github.com/google/googletest/blob/master/googletest/docs/Primer.md)
*   [Google C++ Mocking Framework For
    Dummies](https://github.com/google/googletest/blob/master/googlemock/docs/ForDummies.md)

## Provided abstractions

The following abstractions are provided:

*   **arduino_interface.h** - abstraction for [Arduino's builtin
    functions](https://www.arduino.cc/en/Reference/HomePage) like digitalRead,
    delay, ...
*   **dht_interface.h** - abstraction for the [Adafruit DHT sensor
    library](https://github.com/adafruit/DHT-sensor-library).
*   **adafruit_pcd8544_interface.h** - abstraction for the [Adafruit PCD8544
    Nokia 5110 LCD
    library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library).

## Details

Each abstraction comes with these components:

*   A virtual interface.
*   A mock implementing the virtual interface.
*   An Arduino native implementation of the virtual interface.

## Using the abstractions

### Dependency injection

Let's say that you want to unit test a function that uses the Arduino's
[digitalWrite()](https://www.arduino.cc/en/Reference/DigitalWrite) function.

To do that, instead of importing **Arduino.h** and having the function call
**digitalWrite()** directly, you will use dependancy injection.  Import the
virtual interface and accept it as an argument on the function.

Your function can be defined as follows:

```c++
#include <stdint.h>

#include "arduino/arduino_interface.h"

// Turns on the provided pin number.
void WriteHighToPin(const arduino::ArduinoInterface &ino, uint8_t pin_number) {
  ino.DigitalWrite(pin_number, 1);
}
```

### Passing in the Arduino's native implementation

The main file of your Arduino project will import the actual native
implementation of the virtual interface and pass that in to the function.

```c++
#include <Arduino_impl.h>

// Arduino hardware layer.
const ArduinoImpl ino = ArduinoImpl();

const uint8_t kPinNumber = 13;

void setup() {
  WriteHighToPin(ino, kPinNumber);
}

void loop() {
  // Your code here.
}
```

### Using the mocks in unit tests.

Since the **WriteHighToPin()** function uses dependancy injection, it is now
trivial to write unit tests where you can pass in the provided mock and write
expectations.

```c++
#include "arduino/arduino_interface_mock.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

const uint8_t kPinNumber = 13;

TEST(WriteHighToPinTest, WritesHighToPin) {
  const arduino::MockArduinoInterface mock;
  EXPECT_CALL(mock, DigitalWrite(kPinNumber, 1));
  WriteHighToPin(mock, kPinNumber);
}
```

## Examples

Examine the unit tests included with each of the virtual interfaces to see how
unit tests using these abstractions can be written.
