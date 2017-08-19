#ifndef CHALLENGE_3_CHALLENGE3_H_
#define CHALLENGE_3_CHALLENGE3_H_

#include <map>
#include <string>
#include <vector>

namespace challenge3 {

class SingleXorBreak {
public:
  struct ResultData {
    std::string plaintext;
    int score;
    uint8_t key;

    ResultData(std::string plaintext, int score, uint8_t key)
        : plaintext(plaintext), score(score), key(key) {}
  };
  typedef std::map<char, int> ScoreMap;

  SingleXorBreak(const std::string ciphertext, const ScoreMap scoreMap);

  std::vector<ResultData> getAllResults() const;
  ResultData getBestResult() const;

private:
  const std::string _CIPHERTEXT;
  const ScoreMap _SCORE_MAP;

  int getCandidateScore(const std::string &candidate) const;
  std::vector<std::string> generateCandidateKeys() const;
  int getCharacterScore(char c) const;
  std::string createPatternKey(uint8_t pattern) const;
};
}

#endif // CHALLENGE_1_CHALLENGE3_H_
