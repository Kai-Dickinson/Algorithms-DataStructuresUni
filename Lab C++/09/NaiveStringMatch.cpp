#include "NaiveStringMatch.hpp"

size_t NaiveStringMatch::match(std::string text, std::string pattern) {
    int m = pattern.length();

    if (pattern.length() > text.length()) {
        return (size_t) -1;
    } else if (pattern.length() == 0) {
        return (size_t) 0;
    } else if (text.length() == 0) {
        return (size_t) -1;
    }
    
    for (int s = 0; s <= text.length() - m; s++) {
        bool isFound = true;
        for (int j = 0; j < m; j++) {
            counter.add(2);
            if (text[s+j] != pattern[j]) {
                isFound = false;
                break;
            }
        }
        if (isFound) {
            return s;
        }
    }
    return (size_t) -1;
}
