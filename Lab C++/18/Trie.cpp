#include "Trie.hpp"

Trie::Trie() {
    children = new Trie*[27];
    for (int i = 0; i < 27; ++i) {
        children[i] = NULL;
    }
}

void Trie::insert(std::string s) {
    if (s.length() == 0) {
        children[26] = new Trie();
    } else {
        size_t index = s[0] - 'a';
        if (children[index] == NULL) {
            //Make new child
            children[index] = new Trie();
            
        }
        children[index]->insert(s.substr(1));
    }
}

bool Trie::query(std::string s) {
    if (s.length() == 0) {
        if (children[26] == NULL) {
            return false;
        } else {
            return true;
        }
    } else {
        size_t index2 = s[0] - 'a';
        if (children[index2] == NULL) {
            return false;
        } else {
            return children[index2]->query(s.substr(1, s.length()-1));
        }
    }
}
