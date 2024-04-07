#include "SettingHandler.h"

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

void handleDisplay::handleDisplay(std::string cmd)
{
    
}