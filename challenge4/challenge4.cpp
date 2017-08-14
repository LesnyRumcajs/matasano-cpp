#include "challenge4.h"
#include "../challenge3/challenge3.h"

#include <algorithm>
#include <fstream>
#include <map>
#include <utility>

challenge4::SingleXorDetector::SingleXorDetector(const std::string &filename)
    : _DATA(loadLines(filename)) {}

std::string challenge4::SingleXorDetector::detect() const {
  std::string result;
  const challenge3::SingleXorBreak::ScoreMap SCORE_MAP = {
      {'e', 10}, {'t', 10}, {'a', 9}, {'i', 9}, {'n', 8}, {' ', 8},
      {'s', 7},  {'h', 7},  {'r', 6}, {'d', 6}, {'l', 5}, {'u', 5},
  };

  std::vector<std::pair<std::string, int>> allResults;
  for (const auto &data : _DATA) {
    auto candidates =
        challenge3::SingleXorBreak(data, SCORE_MAP).getAllResults();
    allResults.insert(allResults.end(), candidates.begin(), candidates.end());
  }

  auto bestResult = std::max_element(allResults.begin(), allResults.end(),
                                     [](const auto &left, const auto &right) {
                                       return left.second < right.second;
                                     });

  return bestResult->first;
}

std::vector<std::string>
challenge4::SingleXorDetector::loadLines(std::string filename) const {
  std::vector<std::string> result;

  std::ifstream file(filename.c_str());
  std::string line;
  while (std::getline(file, line)) {
    result.push_back(line);
  }

  return result;
}