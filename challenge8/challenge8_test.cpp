// Copyright 2017, Hubert Bugaj
// Challenge 8 Test
#include <gtest/gtest.h>
#include <string>

#include "../helpers/tools_file.h"
#include "./challenge8.h"

TEST(Challenge8Test, BasicTest) {
  auto data = tools_file::bytesLinesFromHexEncodedFile("../challenge8/8.txt");

  auto result = challenge8::AES_ECB_Detector().detect(data);
  EXPECT_EQ(result, 132);
}