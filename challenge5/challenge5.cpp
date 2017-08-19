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

std::vector<uint8_t>
challenge5::RepeatingKeyXor::decrypt(std::vector<uint8_t> ciphertext,
                                     std::string key) const {
  auto extended_key = extendKey(key, ciphertext.size());

  std::transform(ciphertext.begin(), ciphertext.end(), extended_key.begin(),
                 ciphertext.begin(), [](auto e1, auto e2) { return e1 ^ e2; });

  return ciphertext;
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
