// Copyright 2017, Hubert Bugaj
// Challenge 4 Test
#include <gtest/gtest.h>
#include <string>

#include "./challenge4.h"

TEST(Challenge4Test, BasicTest) {
  auto result{challenge4::SingleXorDetector("../challenge4/4.txt").detect()};
  auto expected{"Now that the party is jumping\n"};

  EXPECT_EQ(expected, result);
}
