#ifndef CHALLENGE_5_CHALLENGE5_H_
#define CHALLENGE_5_CHALLENGE5_H_

#include <string>

namespace challenge5 {
class RepeatingKeyXor {
public:
  std::string encrypt(std::string plaintext, std::string key) const;

private:
  std::string extendKey(std::string key, int targetLength) const;
};
}

#endif
