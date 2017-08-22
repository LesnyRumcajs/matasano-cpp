#ifndef HELPERS_TOOLS_STL_H
#define HELPERS_TOOLS_STL_H

#include <iterator>
#include <vector>

namespace tools_stl {
template <typename Iterator, typename Func>
void chunks(
    Iterator begin, Iterator end,
    std::size_t chunk_size,
    Func function) {
  Iterator chunk_begin;
  Iterator chunk_end;
  chunk_end = chunk_begin = begin;

  do {
    if (std::distance(chunk_end, end) < chunk_size)
      chunk_end = end;
    else
      std::advance(chunk_end, chunk_size);
    function(chunk_begin, chunk_end);
    chunk_begin = chunk_end;
  } while (std::distance(chunk_begin, end) > 0);
}
}

#endif