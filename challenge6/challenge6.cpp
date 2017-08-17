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

int challenge6::RepeatingKeyXorBreaker::decipher() const {
    auto candidate_keysizes = getCandidateKeySizes();

    return 0;
}

std::vector<int> challenge6::RepeatingKeyXorBreaker::getCandidateKeySizes() const {
    std::vector<int> key_sizes(40);
    std::iota(key_sizes.begin(), key_sizes.end(), 2);

    std::vector<std::pair<int, float>> distances;
    for (auto key_size : key_sizes) {
        std::vector<uint8_t> split_lo(_DATA.begin(), _DATA.begin() + key_size);
        std::vector<uint8_t> split_hi(_DATA.begin() + key_size, _DATA.begin() + 2*key_size);

        distances.emplace_back (std::make_pair(key_size, hammingDistance(split_lo, split_hi) * 1.0 / key_size));
    }

    std::sort(distances.begin(), distances.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });

    distances.resize(3);
    std::transform(distances.begin(), distances.end(), key_sizes.begin(),
    [](auto el) -> int {return el.first; });

    return key_sizes;
}
