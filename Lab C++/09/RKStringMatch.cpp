#include "RKStringMatch.hpp"

size_t RKStringMatch::match(std::string text, std::string pattern) {
    int m = pattern.length(); int hm = CalcPattern(pattern);
    bool isFound = false;
    
    if (pattern.length() > text.length()) {
        return (size_t) -1;
    } else if (pattern.length() == 0) {
        return (size_t) 0;
    } else if (text.length() == 0) {
        return (size_t) -1;
    }
    
    
    for (int s = 0; s < text.length(); s++) {
        std::string subStr;
        for (int r = 0; r < m; r++) {
            subStr += text[s+r];
        }
        if (TxtHash(subStr) == hm) {
            isFound = true;
            for (int j = 0; j < m; j++) {
                if (countingChar(text, s+j) != countingChar(pattern, j)) {
                    isFound = false;
                    break;
                }
            }
            if (isFound) {
                return s;
            }
        }
    }
    return (size_t) -1;
}

int RKStringMatch::CalcPattern(std::string val) {
    int totHash = 0;
    for (int i = 0; i < val.length(); i++) {
        totHash += val[i] % 256;
    }
    return totHash;
}

int RKStringMatch::TxtHash(std::string val) {
    int totTxt = 0;
    for (int i = 0; i < val.length(); i++) {
        totTxt += val[i] % 256;
    }
    return totTxt;
}

char RKStringMatch::countingChar(std::string incoming, int value) {
    counter.add(2);
    return incoming[value];
}
