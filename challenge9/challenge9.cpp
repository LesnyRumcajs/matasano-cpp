#include "./challenge9.h"

#include <stdexcept>

void challenge9::addPKCS7Padding(std::vector<uint8_t> &data,
                                 std::size_t block_length) {
  if (block_length < 1) {
    throw std::out_of_range("Invalid block size");
  }
  
  auto missing_bytes = block_length - data.size() % block_length;
  if (0 == missing_bytes) {
    missing_bytes = block_length;
  }

  std::vector<uint8_t> padding(missing_bytes, missing_bytes);
  data.insert(data.end(), padding.begin(), padding.end());
}