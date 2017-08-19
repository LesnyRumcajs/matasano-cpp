#include "challenge3.h"
#include "../challenge2/challenge2.h"

#include <iostream>

challenge3::SingleXorBreak::SingleXorBreak(const std::string ciphertext,
                                           const ScoreMap scoreMap)
    : _CIPHERTEXT(ciphertext), _SCORE_MAP(scoreMap) {}

std::vector<challenge3::SingleXorBreak::ResultData>
challenge3::SingleXorBreak::getAllResults() const {
  auto candidateKeys = generateCandidateKeys();

  std::vector<ResultData> results;
  for (auto key : candidateKeys) {
    auto candidateBytes =
        Botan::hex_decode(challenge2::fixed_xor(_CIPHERTEXT, key));
    auto candidatePlaintext =
        std::string(candidateBytes.begin(), candidateBytes.end());

    auto byteKey = Botan::hex_decode(key);
    results.emplace_back(ResultData(candidatePlaintext,
                                    getCandidateScore(candidatePlaintext),
                                    byteKey.at(0)));
  }

  return results;
}

challenge3::SingleXorBreak::ResultData
challenge3::SingleXorBreak::getBestResult() const {
  auto results = getAllResults();
  auto bestResult = std::max_element(results.begin(), results.end(),
                                     [](const auto &left, const auto &right) {
                                       return left.score < right.score;
                                     });

  return *bestResult;
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
  if (it == _SCORE_MAP.end()) {
    return (c > 65 && c < 122) ? 0 : -500;
  }

  return it->second;
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