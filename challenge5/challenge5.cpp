#include "./challenge5.h"
#include <botan/hex.h>

#include <algorithm>
#include <vector>
std::string challenge5::RepeatingKeyXor::encrypt(std::string plaintext,
                                                 std::string key) const {
  auto extended_key = extendKey(key, plaintext.length());

  std::transform(plaintext.begin(), plaintext.end(), extended_key.begin(),
                 plaintext.begin(), [](auto e1, auto e2) { return e1 ^ e2; });

  std::vector<uint8_t> ciphertext(plaintext.begin(), plaintext.end());
  return Botan::hex_encode(ciphertext, false);
}

std::string challenge5::RepeatingKeyXor::extendKey(std::string key,
                                                   int targetLength) const {
  std::string extendedKey;
  while (extendedKey.length() < targetLength) {
    extendedKey += key;
  }

  extendedKey.resize(targetLength);
  return extendedKey;
}