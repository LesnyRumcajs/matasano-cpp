#ifndef CHALLENGE4_CHALLENGE4_H
#define CHALLENGE4_CHALLENGE4_H

#include <string>
#include <vector>

namespace challenge4 {
class SingleXorDetector {
public:
  SingleXorDetector(const std::string &filename);
  std::string detect() const;

private:
  std::vector<std::string> loadLines(std::string filename) const;
  const std::vector<std::string> _DATA;
};
}

#endif