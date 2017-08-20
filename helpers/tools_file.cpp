#include "tools_file.h"

#include <fstream>
#include <iterator>
#include <botan/base64.h>

namespace tools_file {
std::vector<uint8_t> bytesFromBase64EncodedFile(const std::string &filename) {

  std::ifstream file(filename);

  std::string base64_data{std::istream_iterator<uint8_t>{file},
                          std::istream_iterator<uint8_t>{}};

  auto decoded = Botan::base64_decode(std::move(base64_data));

  return std::vector<uint8_t>(std::make_move_iterator(decoded.begin()),
                              std::make_move_iterator(decoded.end()));
}
}