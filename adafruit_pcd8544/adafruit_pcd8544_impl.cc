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

#include <Adafruit_PCD8544_impl.h>

#include <Adafruit_PCD8544.h>
#include <stdint.h>
#include <stdio.h>

namespace arduino {

AdafruitPcd8544Impl::AdafruitPcd8544Impl(Adafruit_PCD8544 *display)
    : display_(display) {}

AdafruitPcd8544Impl::~AdafruitPcd8544Impl() {}

void AdafruitPcd8544Impl::Begin(uint8_t contrast, uint8_t bias) {
  display_->begin(contrast, bias);
}

void AdafruitPcd8544Impl::ClearDisplay(void) { display_->clearDisplay(); }

void AdafruitPcd8544Impl::SetContrast(uint8_t value) {
  display_->setContrast(value);
}

void AdafruitPcd8544Impl::SetTextSize(uint8_t size) {
  display_->setTextSize(size);
}

void AdafruitPcd8544Impl::SetTextColor(uint16_t color) {
  display_->setTextColor(color);
}

void AdafruitPcd8544Impl::SetCursor(int16_t x, int16_t y) {
  display_->setCursor(x, y);
}

size_t AdafruitPcd8544Impl::Print(int number, int base) {
  return display_->print(number, base);
}

size_t AdafruitPcd8544Impl::Print(unsigned int number, int base) {
  return display_->print(number, base);
}

size_t AdafruitPcd8544Impl::Print(long number, int base) {
  return display_->print(number, base);
}

size_t AdafruitPcd8544Impl::Print(unsigned long number, int base) {
  return display_->print(number, base);
}

size_t AdafruitPcd8544Impl::Print(double number, int digits) {
  return display_->print(number, digits);
}

size_t AdafruitPcd8544Impl::Print(const char characters[]) {
  return display_->print(characters);
}

size_t AdafruitPcd8544Impl::Println(int number, int base) {
  size_t count = display_->print(number, base);
  count += display_->print('\n');
  return count;
}

size_t AdafruitPcd8544Impl::Println(unsigned int number, int base) {
  size_t count = display_->print(number, base);
  count += display_->print('\n');
  return count;
}

size_t AdafruitPcd8544Impl::Println(long number, int base) {
  size_t count = display_->print(number, base);
  count += display_->print('\n');
  return count;
}

size_t AdafruitPcd8544Impl::Println(unsigned long number, int base) {
  size_t count = display_->print(number, base);
  count += display_->print('\n');
  return count;
}

size_t AdafruitPcd8544Impl::Println(double number, int digits) {
  size_t count = display_->print(number, digits);
  count += display_->print('\n');
  return count;
}

size_t AdafruitPcd8544Impl::Println(const char characters[]) {
  size_t count = display_->print(characters);
  count += display_->print('\n');
  return count;
}

void AdafruitPcd8544Impl::Display() { display_->display(); }

} // namespace arduino
