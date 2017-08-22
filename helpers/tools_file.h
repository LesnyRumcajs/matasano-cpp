#ifndef HELPERS_TOOLS_FILE_H
#define HELPERS_TOOLS_FILE_H

#include <string>
#include <vector>

namespace tools_file {
std::vector<uint8_t> bytesFromBase64EncodedFile(const std::string &filename);
std::vector<std::vector<uint8_t>>
bytesLinesFromHexEncodedFile(const std::string &filename);
}

#endif