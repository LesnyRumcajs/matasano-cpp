#ifndef HELPERS_TOOLS_FILE_H
#define HELPERS_TOOLS_FILE_H

#include <vector>
#include <string>

namespace tools_file {
    std::vector<uint8_t> bytesFromBase64EncodedFile(const std::string& filename);
}

#endif