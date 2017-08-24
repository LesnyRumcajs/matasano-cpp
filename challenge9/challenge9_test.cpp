// Copyright 2017, Hubert Bugaj
// Challenge 9 Test
#include <gtest/gtest.h>
#include <string>

#include "./challenge9.h"

TEST(Challenge9Test, BasicTest) {

  std::vector<uint8_t> expected{'Y', 'E', 'L',  'L',  'O',  'W', ' ',
                                'S', 'U', 'B',  'M',  'A',  'R', 'I',
                                'N', 'E', 0x04, 0x04, 0x04, 0x04};

  std::string plaintext = "YELLOW SUBMARINE";
  std::vector<uint8_t> result(plaintext.begin(), plaintext.end());
  challenge9::addPKCS7Padding(result, 20);

  EXPECT_EQ(result, expected);
}

TEST(Challenge9Test, PlaintextMultipleOfBlock) {
  std::vector<uint8_t> expected{'Y', 'E', 'L',  0x03,  0x03,  0x03};
  std::vector<uint8_t> result{'Y', 'E', 'L'};

  challenge9::addPKCS7Padding(result, 3);

  EXPECT_EQ(result, expected);
}

TEST(Challenge9Test, EmptyPlaintext) {
  std::vector<uint8_t> expected(20, 0x14);
  std::vector<uint8_t> result;
  challenge9::addPKCS7Padding(result, 20);

  EXPECT_EQ(result, expected);
}

TEST(Challenge9Test, NonPositiveBlockSizeShouldThrowOutOfRange) {
  std::vector<uint8_t> data;
  EXPECT_THROW(challenge9::addPKCS7Padding(data, 0), std::out_of_range);
}
