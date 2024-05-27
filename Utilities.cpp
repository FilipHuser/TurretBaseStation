#include "Utilities.h"

std::vector<std::string> parseString(const std::string input, char delimiter) {
    std::vector<std::string> substrings;
    size_t start = 0;
    size_t end = 0;

    while ((end = input.find(delimiter, start)) != std::string::npos) {
        substrings.push_back(input.substr(start, end - start));
        start = end + 1; 
    }

    // Push the last substring (after the last delimiter)
    substrings.push_back(input.substr(start));

    return substrings;
}

std::string aes_encrypt(const std::string& plaintext, unsigned char* key) {
    AES_KEY aesKey;
    AES_set_encrypt_key(key, 128, &aesKey);

    unsigned char iv[AES_BLOCK_SIZE] = {0}; // Initialize to all zeros

    std::string ciphertext(plaintext.size(), '\0'); // Initialize with the same size as plaintext

    AES_cbc_encrypt(reinterpret_cast<const unsigned char*>(plaintext.data()),
                    const_cast<unsigned char*>(reinterpret_cast<const unsigned char*>(ciphertext.data())),
                    plaintext.size(), &aesKey, iv, AES_ENCRYPT);

    return ciphertext;
}

std::string aes_decrypt(const std::string& ciphertext, unsigned char* key) {
    AES_KEY aesKey;
    AES_set_decrypt_key(key, 128, &aesKey);

    unsigned char iv[AES_BLOCK_SIZE] = {0}; // Initialize to all zeros

    std::string decryptedtext(ciphertext.size(), '\0'); // Initialize with the same size as ciphertext

    AES_cbc_encrypt(reinterpret_cast<const unsigned char*>(ciphertext.data()),
                    const_cast<unsigned char*>(reinterpret_cast<const unsigned char*>(decryptedtext.data())),
                    ciphertext.size(), &aesKey, iv, AES_DECRYPT); 

    return decryptedtext;
}