#ifndef CHALLENGE_5_CHALLENGE5_H_
#define CHALLENGE_5_CHALLENGE5_H_

#include <string>
#include <vector>

namespace challenge5 {
class RepeatingKeyXor {
public:
  std::string encrypt(std::string plaintext, std::string key) const;
  std::vector<uint8_t> decrypt(std::vector<uint8_t> ciphertext,
                               std::string key) const;

private:
  std::string extendKey(std::string key, int targetLength) const;
};
}

#endif
