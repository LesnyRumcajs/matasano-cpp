#include "./challenge8.h"

#include "../helpers/tools_stl.h"
#include <algorithm>
#include <botan/block_cipher.h>

int challenge8::AES_ECB_Detector::detect(
    const ECB_Candidates &candidates) const {
  auto unique_blocks_count = getUniqueBlocksCounts(candidates);

  auto min =
      std::min_element(unique_blocks_count.begin(), unique_blocks_count.end());
  auto max =
      std::max_element(unique_blocks_count.begin(), unique_blocks_count.end());

  return *min == *max ? -1 : std::distance(unique_blocks_count.begin(), min);
}

std::vector<uint8_t> challenge8::AES_ECB_Detector::getUniqueBlocksCounts(
    ECB_Candidates candidates) const {
  std::unique_ptr<Botan::BlockCipher> cipher(
      Botan::BlockCipher::create("AES-128"));
  cipher->set_key(std::move(std::vector<uint8_t>(BLOCK_SIZE)));

  std::vector<uint8_t> unique_blocks_count;

  for (const auto &ciphertext : candidates) {
    std::vector<uint8_t> plaintext(ciphertext.size() + BLOCK_SIZE);
    cipher->decrypt(ciphertext, plaintext);

    std::set<std::vector<uint8_t>> blocks;
    auto f = [&](auto &b, auto &e) { blocks.emplace(b, e); };

    tools_stl::chunks(plaintext.begin(), plaintext.end(), BLOCK_SIZE, f);

    unique_blocks_count.emplace_back(blocks.size());
  }

  return unique_blocks_count;
}
