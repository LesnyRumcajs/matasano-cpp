// Copyright 2017, Hubert Bugaj
// Challenge 5 Test
#include <gtest/gtest.h>
#include <string>

#include "./challenge5.h"

TEST(Challenge5Test, BasicTest) {
  auto plaintext = "Burning 'em, if you ain't"
                   " quick and nimble\nI go crazy"
                   " when I hear a cymbal";

  auto key = "ICE";
  auto expectedCiphertext = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d"
                            "63343c2a26226324272765272a282b2f20430a652e2c652a31"
                            "24333a653e2b2027630c692b20283165286326302e27282f";

  auto resultCiphertext = challenge5::RepeatingKeyXor().encrypt(plaintext, key);
  EXPECT_EQ(expectedCiphertext, resultCiphertext);
}

#include <botan/hex.h>

TEST(Challenge5Test, EncryptDecrypt) {
  std::string plaintext = "Burning 'em, if you ain't"
                          " quick and nimble\nI go crazy"
                          " when I hear a cymbal";

  auto key = "ICE";

  auto resultCiphertext =
      Botan::hex_decode(challenge5::RepeatingKeyXor().encrypt(plaintext, key));
  auto resultPlaintext = challenge5::RepeatingKeyXor().decrypt(
      {resultCiphertext.begin(), resultCiphertext.end()}, key);

  std::vector<uint8_t> plaintextVec(plaintext.begin(), plaintext.end());
  EXPECT_EQ(plaintextVec, resultPlaintext);
  // EXPECT_THAT(plaintext, testing::ContainerEq(resultPlaintext));
}
