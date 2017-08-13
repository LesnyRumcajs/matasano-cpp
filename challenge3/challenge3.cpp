#include "challenge3.h"
#include "../challenge2/challenge2.h"

#include <iostream>

challenge3::SingleXorBreak::SingleXorBreak(const std::string ciphertext,
                                           const ScoreMap scoreMap)
    : _CIPHERTEXT(ciphertext), _SCORE_MAP(scoreMap) {}

std::vector<std::pair<std::string, int>>
challenge3::SingleXorBreak::getAllResults() const {
  auto candidateKeys = generateCandidateKeys();

  std::vector<std::pair<std::string, int>> results;
  for (const auto &key : candidateKeys) {
    auto candidateBytes =
        Botan::hex_decode(challenge2::fixed_xor(_CIPHERTEXT, key));
    auto candidatePlaintext =
        std::string(candidateBytes.begin(), candidateBytes.end());

    results.emplace_back(std::make_pair(candidatePlaintext,
                                        getCandidateScore(candidatePlaintext)));
  }

  return results;
}

std::string challenge3::SingleXorBreak::getBestResult() const {
  auto results = getAllResults();
  auto bestResult =
      std::max_element(results.begin(), results.end(),
                       [](const std::pair<std::string, int> &left,
                          const std::pair<std::string, int> &right) {
                         return left.second < right.second;
                       });

  return bestResult->first;
}

std::vector<std::string>
challenge3::SingleXorBreak::generateCandidateKeys() const {
  std::vector<std::string> keys;

  for (uint8_t i{1}; i < 0xFF; ++i) {
    keys.emplace_back(createPatternKey(i));
  }

  return keys;
}

int challenge3::SingleXorBreak::getCandidateScore(
    const std::string &candidate) const {
  int result{0};
  for (const auto c : candidate) {
    result += getCharacterScore(c);
  }

  return result;
}

int challenge3::SingleXorBreak::getCharacterScore(char c) const {
  auto it = _SCORE_MAP.find(c);
  return it == _SCORE_MAP.end() ? 0 : it->second;
}

std::string
challenge3::SingleXorBreak::createPatternKey(uint8_t pattern) const {
  uint8_t pattern_array[]{pattern};

  std::string key;
  while (key.length() < _CIPHERTEXT.length()) {
    key.append(Botan::hex_encode(pattern_array, 1));
  }

  return key;
}