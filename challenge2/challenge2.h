// Copyright 2017, Hubert Bugaj

#ifndef CHALLENGE_2_CHALLENGE2_H_
#define CHALLENGE_2_CHALLENGE2_H_

#include <botan/base64.h>
#include <botan/hex.h>

#include <functional>
#include <string>

namespace challenge2 {
std::string fixed_xor(const std::string &input_hex,
                      const std::string &key_hex) {
  auto data_binary = Botan::hex_decode(input_hex);
  auto key_binary = Botan::hex_decode(key_hex);

  std::transform(data_binary.begin(), data_binary.end(), key_binary.begin(),
                 data_binary.begin(), [](auto e1, auto e2) { return e1 ^ e2; });

  return Botan::hex_encode(data_binary, false);
}
} // namespace challenge2
#endif //  CHALLENGE_2_CHALLENGE2_H_
