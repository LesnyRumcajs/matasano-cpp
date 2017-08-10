#include "challenge1.h"

std::string challenge1::hex2base64(const std::string &hex_data) {
  auto binary_data = Botan::hex_decode(hex_data);
  return Botan::base64_encode(binary_data);
}