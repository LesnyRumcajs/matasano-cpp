#include "./challenge6.h"

#include <botan/base64.h>
#include <fstream>
#include <iostream>
#include <iterator>

challenge6::RepeatingKeyXorBreaker::RepeatingKeyXorBreaker(std::string filename)
    : _DATA(getBytesFromBase64EncodedFile(filename)) {}

std::vector<uint8_t>
challenge6::RepeatingKeyXorBreaker::getBytesFromBase64EncodedFile(
    std::string filename) {

  std::ifstream file(filename);

  std::string base64_data{std::istream_iterator<uint8_t>{file},
                          std::istream_iterator<uint8_t>{}};

  auto decoded = Botan::base64_decode(std::move(base64_data));

  return std::vector<uint8_t>(std::make_move_iterator(decoded.begin()),
                              std::make_move_iterator(decoded.end()));
}

int challenge6::RepeatingKeyXorBreaker::decipher() const { return 0; }