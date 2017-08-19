#include "./challenge6.h"

#include <botan/base64.h>
#include <botan/hex.h>

#include "../challenge3/challenge3.h"
#include "../challenge5/challenge5.h"
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

std::vector<uint8_t> challenge6::RepeatingKeyXorBreaker::decipher() const {
  challenge3::SingleXorBreak::ScoreMap scoreMap = {
      {'e', 25}, {'t', 24}, {'a', 23}, {'o', 22}, {'i', 21}, {'n', 20},
      {'s', 19}, {'r', 18}, {'h', 17}, {'l', 16}, {'d', 15}, {'c', 14},
      {'u', 13}, {'m', 12}, {'f', 11}, {'g', 10}, {'p', 9},  {'y', 8},
      {'w', 7},  {'b', 6},  {'v', 5},  {'k', 4},  {'x', 3},  {'j', 2},
      {'q', 1},  {'E', 25}, {'T', 24}, {'A', 23}, {'O', 22}, {'I', 21},
      {'N', 20}, {'S', 19}, {'R', 18}, {'H', 17}, {'L', 16}, {'D', 15},
      {'C', 14}, {'U', 13}, {'M', 12}, {'F', 11}, {'G', 10}, {'P', 9},
      {'Y', 8},  {'W', 7},  {'B', 6},  {'V', 5},  {'K', 4},  {'X', 3},
      {'J', 2},  {'Q', 1},  {'\n', 5}, {'\'', 5}, {' ', 20}, {'-', 1}};

  auto keys = getCandidateKeys(scoreMap);

  std::vector<std::pair<std::vector<uint8_t>, double>> results;
  for (auto key : keys) {
    auto plaintext =
        challenge5::RepeatingKeyXor().decrypt(_DATA, {key.begin(), key.end()});
    results.emplace_back(
        std::make_pair(plaintext, evaluate_plaintext(plaintext, scoreMap)));
  }

  auto bestResult = std::max_element(results.begin(), results.end(),
                                     [](const auto &left, const auto &right) {
                                       return left.second < right.second;
                                     });

  return bestResult->first;
}

std::vector<std::vector<uint8_t>>
challenge6::RepeatingKeyXorBreaker::getCandidateKeys(
    std::map<char, int> scoreMap) const {
  auto candidate_keysizes = getCandidateKeySizes();

  std::vector<std::vector<uint8_t>> keys;
  for (auto key_size : candidate_keysizes) {
    auto transposed = getDataInBlocks(key_size);
    std::vector<uint8_t> key;
    for (const auto &block : transposed) {
      std::string block_string = Botan::hex_encode(block);

      auto key_chunk = challenge3::SingleXorBreak(block_string, scoreMap)
                           .getBestResult()
                           .key;

      key.emplace_back(key_chunk);
    }
    keys.emplace_back(key);
  }

  return keys;
}

double challenge6::RepeatingKeyXorBreaker::evaluate_plaintext(
    std::vector<uint8_t> plaintext, std::map<char, int> scoreMap) const {
  double result{.0};

  for (const auto ch : plaintext) {
    auto it = scoreMap.find(ch);
    if (it == scoreMap.end()) {
      result += (ch > 65 && ch < 122) ? 0 : -5000;
    }

    result += it->second;
  }

  return result / plaintext.size();
}

std::vector<int>
challenge6::RepeatingKeyXorBreaker::getCandidateKeySizes() const {
  std::vector<int> key_sizes(30);
  std::iota(key_sizes.begin(), key_sizes.end(), 2);

  std::vector<std::pair<int, float>> distances;
  for (auto key_size : key_sizes) {
    std::vector<uint8_t> split_lo(_DATA.begin(), _DATA.begin() + key_size);
    std::vector<uint8_t> split_hi(_DATA.begin() + key_size,
                                  _DATA.begin() + 2 * key_size);

    distances.emplace_back(std::make_pair(
        key_size, hammingDistance(split_lo, split_hi) * 1.0 / key_size));
  }

  std::sort(distances.begin(), distances.end(),
            [](auto &left, auto &right) { return left.second < right.second; });

  std::transform(distances.begin(), distances.end(), key_sizes.begin(),
                 [](auto el) -> int { return el.first; });

  return key_sizes;
}

std::vector<std::vector<uint8_t>>
challenge6::RepeatingKeyXorBreaker::getDataInBlocks(int block_size) const {
  std::vector<std::vector<uint8_t>> result;
  result.resize(block_size);

  for (auto i{0}; i < _DATA.size(); ++i) {
    result.at(i % block_size).push_back(_DATA.at(i));
  }

  return result;
}
