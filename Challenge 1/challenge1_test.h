// Copyright 2017, Hubert Bugaj
// Challenge 1 Test
#include <cxxtest/TestSuite.h>

#include <string>

#include "./challenge1.h"

class Challenge1_test : public CxxTest::TestSuite {
 public:
    void test_hex2base64(void) {
        const std::string TEST_CASE = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
        const std::string EXPECTED_RESULT = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
        auto result = challenge1::hex2base64(TEST_CASE);
        TS_ASSERT_EQUALS(EXPECTED_RESULT, result);
        TS_ASSERT(2+2 == 4);
    }
};
