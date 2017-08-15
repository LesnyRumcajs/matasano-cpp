// Copyright 2017, Hubert Bugaj
// Challenge 6 Test
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

TEST(Challenge6Test, HammingDistanceShouldWorkOnVectors) {
  std::vector<uint8_t> s1{'t', 'h', 'i', 's', ' ', 'i', 's',
                          ' ', 'a', ' ', 't', 'e', 's', 't'};
  std::vector<uint8_t> s2{'w', 'o', 'k', 'k', 'a', ' ', 'w',
                          'o', 'k', 'k', 'a', '!', '!', '!'};

  auto expected{37};
  auto result{challenge6::hammingDistance(s1, s2)};

  EXPECT_EQ(expected, result);
}