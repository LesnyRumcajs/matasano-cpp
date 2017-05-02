// Copyright 2017, Hubert Bugaj
// Challenge 2 Test
#include <cxxtest/TestSuite.h>

#include <string>

#include "./challenge2.h"

class Challenge1_test : public CxxTest::TestSuite {
 public:
    void test_hex2base64(void) {
        const std::string TEST_CASE = "1c0111001f010100061a024b53535009181c";
        const std::string KEY = "686974207468652062756c6c277320657965";
        const std::string EXPECTED_RESULT = "746865206b696420646f6e277420706c6179";
        auto result = challenge2::fixed_xor(TEST_CASE, KEY);
        TS_ASSERT_EQUALS(EXPECTED_RESULT, result);
    }
};
