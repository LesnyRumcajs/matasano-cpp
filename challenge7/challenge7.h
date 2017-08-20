#ifndef CHALLENGE7_CHALLENGE7_H
#define CHALLENGE7_CHALLENGE7_H

#include <botan/block_cipher.h>
#include <vector>

namespace challenge7 {
template <typename T> T decryptAES_ECB(T data, T key) {
  std::unique_ptr<Botan::BlockCipher> cipher(
      Botan::BlockCipher::create("AES-128"));
  cipher->set_key(key);
  cipher->decrypt(data);

  // remove PKCS#7 padding
  data.erase(data.end() - data[data.size() - 1], data.end());

  return data;
}
}

#endif