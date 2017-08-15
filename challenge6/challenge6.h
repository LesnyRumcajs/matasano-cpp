#ifndef CHALLENGE6_CHALLENGE6_H
#define CHALLENGE6_CHALLENGE6_H

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

namespace challenge6 {
template <class T> int hammingDistance(T s1, T s2) {
  if (s1.length() != s2.length())
    return -1;

  std::vector<int> results(s1.length());
  std::transform(s1.begin(), s1.end(), s2.begin(), results.begin(),
                 [](auto e1, auto e2) {
                   auto distance{0};
                   auto val = e1 ^ e2;
                   while (val) {
                     ++distance;
                     val &= val - 1;
                   }
                   return distance;
                 });

  return std::accumulate(results.begin(), results.end(), 0);
}
}

#endif