// Copyright 2017, Hubert Bugaj
// Challenge 1 Test
#include <gtest/gtest.h>
#include <string>

#include "./challenge1.h"

TEST(Challenge1Test, BasicTest) {
  EXPECT_EQ("SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t",
            challenge1::hex2base64("49276d206b696c6c696e6720796f757220627261696"
                                   "e206c696b65206120706f69736f6e6f7573206d7573"
                                   "68726f6f6d"));
}
