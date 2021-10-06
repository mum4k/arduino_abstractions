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

#include "adafruit_pcd8544/adafruit_pcd8544_interface.h"
#include "adafruit_pcd8544/adafruit_pcd8544_interface_mock.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::Matcher;
using ::testing::Return;

namespace arduino
{
  namespace
  {

    void CallBegin(AdafruitPcd8544Interface *display, uint8_t contrast,
                   uint8_t bias)
    {
      display->Begin(contrast, bias);
    }

    void CallClearDisplay(AdafruitPcd8544Interface *display)
    {
      display->ClearDisplay();
    }

    void CallSetContrast(AdafruitPcd8544Interface *display, uint8_t value)
    {
      display->SetContrast(value);
    }

    void CallSetTextSize(AdafruitPcd8544Interface *display, uint8_t size)
    {
      display->SetTextSize(size);
    }

    void CallSetTextColor(AdafruitPcd8544Interface *display, uint16_t color)
    {
      display->SetTextColor(color);
    }

    void CallSetCursor(AdafruitPcd8544Interface *display, uint16_t x, uint16_t y)
    {
      display->SetCursor(x, y);
    }

    void CallPrint(AdafruitPcd8544Interface *display, int number, int base)
    {
      display->Print(number, base);
      display->Println(number, base);
    }

    void CallPrint(AdafruitPcd8544Interface *display, unsigned int number,
                   int base)
    {
      display->Print(number, base);
      display->Println(number, base);
    }

    void CallPrint(AdafruitPcd8544Interface *display, long number, int base)
    {
      display->Print(number, base);
      display->Println(number, base);
    }

    void CallPrint(AdafruitPcd8544Interface *display, unsigned long number,
                   int base)
    {
      display->Print(number, base);
      display->Println(number, base);
    }

    void CallPrint(AdafruitPcd8544Interface *display, double number, int digits)
    {
      display->Print(number, digits);
      display->Println(number, digits);
    }

    void CallPrint(AdafruitPcd8544Interface *display, const char characters[])
    {
      display->Print(characters);
      display->Println(characters);
    }

    void CallDisplay(AdafruitPcd8544Interface *display) { display->Display(); }

    class AdafruitPcd8544InterfaceTest : public ::testing::Test
    {
    protected:
      AdafruitPcd8544InterfaceTest() {}

      AdafruitPcd8544InterfaceMock mock_;
    };

    TEST_F(AdafruitPcd8544InterfaceTest, MocksBegin)
    {
      EXPECT_CALL(mock_, Begin(kDefaultContrast, kDefaultBias));
      CallBegin(&mock_, kDefaultContrast, kDefaultBias);
    }

    TEST_F(AdafruitPcd8544InterfaceTest, MocksClearDisplay)
    {
      EXPECT_CALL(mock_, ClearDisplay());
      CallClearDisplay(&mock_);
    }

    TEST_F(AdafruitPcd8544InterfaceTest, MocksSetContrast)
    {
      EXPECT_CALL(mock_, SetContrast(kDefaultContrast));
      CallSetContrast(&mock_, kDefaultContrast);
    }

    TEST_F(AdafruitPcd8544InterfaceTest, MocksSetTextSize)
    {
      const uint8_t size = 42;
      EXPECT_CALL(mock_, SetTextSize(size));
      CallSetTextSize(&mock_, size);
    }

    TEST_F(AdafruitPcd8544InterfaceTest, MocksSetTextColor)
    {
      const uint16_t color = 1;
      EXPECT_CALL(mock_, SetTextColor(color));
      CallSetTextColor(&mock_, color);
    }

    TEST_F(AdafruitPcd8544InterfaceTest, MocksSetCursor)
    {
      const uint16_t x = 1;
      const uint16_t y = 1;
      EXPECT_CALL(mock_, SetCursor(x, y));
      CallSetCursor(&mock_, x, y);
    }

    TEST_F(AdafruitPcd8544InterfaceTest, MocksPrintInt)
    {
      const int number = 42;
      EXPECT_CALL(mock_, Print(Matcher<int>(number), kBaseTen));
      EXPECT_CALL(mock_, Println(Matcher<int>(number), kBaseTen));
      CallPrint(&mock_, number, kBaseTen);
    }

    TEST_F(AdafruitPcd8544InterfaceTest, MocksPrintUnsignedInt)
    {
      const unsigned int number = 42;
      EXPECT_CALL(mock_, Print(Matcher<unsigned int>(number), kBaseTen));
      EXPECT_CALL(mock_, Println(Matcher<unsigned int>(number), kBaseTen));
      CallPrint(&mock_, number, kBaseTen);
    }

    TEST_F(AdafruitPcd8544InterfaceTest, MocksPrintLong)
    {
      const long number = 42;
      EXPECT_CALL(mock_, Print(Matcher<long>(number), kBaseTen));
      EXPECT_CALL(mock_, Println(Matcher<long>(number), kBaseTen));
      CallPrint(&mock_, number, kBaseTen);
    }

    TEST_F(AdafruitPcd8544InterfaceTest, MocksPrintUnsignedLong)
    {
      const unsigned long number = 42;
      EXPECT_CALL(mock_, Print(Matcher<unsigned long>(number), kBaseTen));
      EXPECT_CALL(mock_, Println(Matcher<unsigned long>(number), kBaseTen));
      CallPrint(&mock_, number, kBaseTen);
    }

    TEST_F(AdafruitPcd8544InterfaceTest, MocksPrintDouble)
    {
      const double number = 42.0;
      const int digits = 6;
      EXPECT_CALL(mock_, Print(Matcher<double>(number), digits));
      EXPECT_CALL(mock_, Println(Matcher<double>(number), digits));
      CallPrint(&mock_, number, digits);
    }

    TEST_F(AdafruitPcd8544InterfaceTest, MocksPrintCharacters)
    {
      const char text[] = "text";
      EXPECT_CALL(mock_, Print(text));
      EXPECT_CALL(mock_, Println(text));
      CallPrint(&mock_, text);
    }

    TEST_F(AdafruitPcd8544InterfaceTest, MocksDisplay)
    {
      EXPECT_CALL(mock_, Display());
      CallDisplay(&mock_);
    }

  } // namespace
} // namespace arduino
