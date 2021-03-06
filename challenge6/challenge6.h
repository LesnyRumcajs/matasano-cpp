#ifndef CHALLENGE6_CHALLENGE6_H
#define CHALLENGE6_CHALLENGE6_H

#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <vector>

namespace challenge6 {
template <class T> int hammingDistance(T s1, T s2) {
  if (s1.size() != s2.size())
    return -1;

  std::vector<int> results(s1.size());
  std::transform(s1.begin(), s1.end(), s2.begin(), results.begin(),
                 [](auto e1, auto e2) {
                   auto distance{0};

                   // number with differing bits
                   auto val = e1 ^ e2;

                   // using Brian Kernighan algorithm to count bits
                   while (val) {
                     ++distance;
                     val &= val - 1;
                   }
                   return distance;
                 });

  return std::accumulate(results.begin(), results.end(), 0);
}

class RepeatingKeyXorBreaker {
public:
  RepeatingKeyXorBreaker(std::string filename);
  std::vector<uint8_t> decipher() const;

private:
  const std::vector<uint8_t> _DATA;
  static std::vector<uint8_t>
  getBytesFromBase64EncodedFile(std::string filename);
  std::vector<int> getCandidateKeySizes() const;
  std::vector<std::vector<uint8_t>> getDataInBlocks(int block_size) const;
  double evaluate_plaintext(std::vector<uint8_t> plaintext,
                            std::map<char, int> scoreMap) const;
  std::vector<std::vector<uint8_t>>
  getCandidateKeys(std::map<char, int> scoreMap) const;
};
}

#endif
