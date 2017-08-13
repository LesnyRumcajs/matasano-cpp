// Copyright 2017, Hubert Bugaj
// Challenge 3 Test
#include <gtest/gtest.h>
#include <string>

#include "./challenge3.h"

TEST(Challenge3Test, BasicTest) {
  challenge3::SingleXorBreak::ScoreMap scoreMap = {
      {'e', 10}, {'t', 10}, {'a', 9}, {'i', 9}, {'n', 8}, {' ', 8},
      {'s', 7},  {'h', 7},  {'r', 6}, {'d', 6}, {'l', 5}, {'u', 5},
  };

  challenge3::SingleXorBreak test(
      "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a39"
                "3b3736",
      std::move(scoreMap));

  auto result{test.getBestResult()};
  auto expected{"Cooking MC's like a pound of bacon"};

  EXPECT_EQ(expected, result);
}
