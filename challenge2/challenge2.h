// Copyright 2017, Hubert Bugaj

#ifndef CHALLENGE_2_CHALLENGE2_H_
#define CHALLENGE_2_CHALLENGE2_H_

#include <botan/base64.h>
#include <botan/hex.h>

#include <functional>
#include <string>

namespace challenge2 {
std::string fixed_xor(const std::string &input_hex, const std::string &key_hex);
} // namespace challenge2
#endif //  CHALLENGE_2_CHALLENGE2_H_
