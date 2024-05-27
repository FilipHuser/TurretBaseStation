#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>
#include <string>
#include <openssl/aes.h>

std::vector<std::string> parseString(const std::string input, char delimiter);

std::string aes_encrypt(const std::string& plaintext, unsigned char* key);

std::string aes_decrypt(const std::string& ciphertext, unsigned char* key);

#endif //UTILITIES_H