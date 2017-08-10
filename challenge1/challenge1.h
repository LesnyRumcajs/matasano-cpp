// Copyright 2017, Hubert Bugaj

#ifndef CHALLENGE_1_CHALLENGE1_H_
#define CHALLENGE_1_CHALLENGE1_H_

#include <botan/base64.h>
#include <botan/hex.h>

#include <string>

namespace challenge1 {
std::string hex2base64(const std::string &hex_data);
}

#endif //  CHALLENGE_1_CHALLENGE1_H_
