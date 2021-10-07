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

#include "software_serial/software_serial_interface.h"
#include "software_serial/software_serial_interface_mock.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::Return;

namespace arduino
{
  namespace
  {

    void CallInitialize(SoftwareSerialInterface *serial, long speed)
    {
      serial->Initialize(speed);
    }

    int CallBytesAvailable(SoftwareSerialInterface *serial)
    {
      return serial->BytesAvailable();
    }

    bool CallHadOverflow(SoftwareSerialInterface *serial)
    {
      return serial->HadOverflow();
    }

    void CallSetTimeout(SoftwareSerialInterface *serial, unsigned long timeout_ms)
    {
      serial->SetTimeout(timeout_ms);
    }

    size_t CallWriteBytes(SoftwareSerialInterface *serial, const char *data)
    {
      return serial->WriteBytes(data);
    }

    size_t CallReadBytes(SoftwareSerialInterface *serial, size_t length,
                         char *buffer)
    {
      return serial->ReadBytes(length, buffer);
    }

    class SoftwareSerialInterfaceTest : public ::testing::Test
    {
    protected:
      SoftwareSerialInterfaceTest() {}

      SoftwareSerialInterfaceMock mock_;
    };

    TEST_F(SoftwareSerialInterfaceTest, MocksInitialize)
    {
      const long speed = 9600;
      EXPECT_CALL(mock_, Initialize(speed));
      CallInitialize(&mock_, speed);
    }

    TEST_F(SoftwareSerialInterfaceTest, MocksBytesAvailable)
    {
      const int expected = 42;
      EXPECT_CALL(mock_, BytesAvailable()).WillOnce(Return(expected));
      EXPECT_EQ(expected, CallBytesAvailable(&mock_));
    }

    TEST_F(SoftwareSerialInterfaceTest, MocksHadOverflow)
    {
      const bool expected = true;
      EXPECT_CALL(mock_, HadOverflow()).WillOnce(Return(expected));
      EXPECT_EQ(expected, CallHadOverflow(&mock_));
    }

    TEST_F(SoftwareSerialInterfaceTest, MocksSetTimeout)
    {
      const unsigned long timeout_ms = 42;
      EXPECT_CALL(mock_, SetTimeout(timeout_ms));
      CallSetTimeout(&mock_, timeout_ms);
    }

    TEST_F(SoftwareSerialInterfaceTest, MocksWriteBytes)
    {
      const char data[] = "data";
      const size_t expected = 1;
      EXPECT_CALL(mock_, WriteBytes(data)).WillOnce(Return(expected));
      EXPECT_EQ(expected, CallWriteBytes(&mock_, data));
    }

    TEST_F(SoftwareSerialInterfaceTest, MocksReadBytes)
    {
      const size_t length = 2;
      char buffer[length];
      const size_t expected = 1;
      EXPECT_CALL(mock_, ReadBytes(length, buffer)).WillOnce(Return(expected));
      EXPECT_EQ(expected, CallReadBytes(&mock_, length, buffer));
    }

  } // namespace
} // namespace arduino
