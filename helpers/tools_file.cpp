#include "tools_file.h"

#include <botan/base64.h>
#include <botan/hex.h>
#include <fstream>
#include <iterator>

namespace tools_file {
std::vector<uint8_t> bytesFromBase64EncodedFile(const std::string &filename) {

  std::ifstream file(filename);

  std::string base64_data{std::istream_iterator<uint8_t>{file},
                          std::istream_iterator<uint8_t>{}};

  auto decoded = Botan::base64_decode(std::move(base64_data));

  return std::vector<uint8_t>(std::make_move_iterator(decoded.begin()),
                              std::make_move_iterator(decoded.end()));
}

std::vector<std::vector<uint8_t>>
bytesLinesFromHexEncodedFile(const std::string &filename) {
  std::vector<std::vector<uint8_t>> results;

  std::ifstream file(filename);
  for (std::string line; std::getline(file, line); /**/) {
    results.emplace_back(Botan::hex_decode(line));
  }

  return results;
}
}