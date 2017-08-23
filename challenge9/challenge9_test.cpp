// Copyright 2017, Hubert Bugaj
// Challenge 9 Test
#include <gtest/gtest.h>
#include <string>

#include "./challenge9.h"

TEST(Challenge9Test, BasicTest) {
  std::string plaintext = "YELLOW SUBMARINE";
  std::vector<uint8_t> result(plaintext.begin(), plaintext.end());

  std::vector<uint8_t> expected{'Y', 'E', 'L',  'L',  'O',  'W', ' ',
                                'S', 'U', 'B',  'M',  'A',  'R', 'I',
                                'N', 'E', 0x04, 0x04, 0x04, 0x04};
  challenge9::addPKCS7Padding(result, 20);

  EXPECT_EQ(result, expected);
}