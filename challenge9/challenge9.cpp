#include "./challenge9.h"

void challenge9::addPKCS7Padding(std::vector<uint8_t> &data,
                                 std::size_t block_length) {
  auto missing_bytes = block_length - data.size() % block_length;
  if (0 == missing_bytes) {
    missing_bytes = block_length;
  }

  std::vector<uint8_t> padding(missing_bytes, missing_bytes);
  data.insert(data.end(), padding.begin(), padding.end());
}