// Copyright 2017, Hubert Bugaj
// Challenge 4 Test
#include <gtest/gtest.h>
#include <string>

#include "./challenge6.h"

TEST(Challenge6Test, HammingDistanceTestCorrectInput) {
  std::string s1{"this is a test"};
  std::string s2{"wokka wokka!!!"};

  auto expected{37};
  auto result{challenge6::hammingDistance(s1, s2)};

  EXPECT_EQ(expected, result);
}

TEST(Challenge6Test, HammingDistanceTestWrongLength) {
  std::string s1{"this is a test"};
  std::string s2{"wokka wokka!!!!"};

  auto expected{-1};
  auto result{challenge6::hammingDistance(s1, s2)};

  EXPECT_EQ(expected, result);
}
