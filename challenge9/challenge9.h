#ifndef CHALLENGE9_CHALLENGE9_H
#define CHALLENGE9_CHALLENGE9_H

#include <cstdint>
#include <vector>
namespace challenge9 {
void addPKCS7Padding(std::vector<uint8_t> &data, std::size_t block_length);
}

#endif