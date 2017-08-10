#include "challenge2.h"

std::string challenge2::fixed_xor(const std::string &input_hex,
                                  const std::string &key_hex) {
  auto data_binary = Botan::hex_decode(input_hex);
  auto key_binary = Botan::hex_decode(key_hex);

  std::transform(data_binary.begin(), data_binary.end(), key_binary.begin(),
                 data_binary.begin(), [](auto e1, auto e2) { return e1 ^ e2; });

  return Botan::hex_encode(data_binary, false);
}
