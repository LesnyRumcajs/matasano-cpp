#ifndef CHALLENGE8_CHALLENGE8_H
#define CHALLENGE8_CHALLENGE8_H

#include <cstdint>
#include <vector>

namespace challenge8 {
class AES_ECB_Detector {
public:
  typedef std::vector<std::vector<uint8_t>> ECB_Candidates;
  int detect(const ECB_Candidates &data) const;

private:
  static const int BLOCK_SIZE = 16;

  std::vector<uint8_t> getUniqueBlocksCounts(ECB_Candidates) const;
};
}

#endif