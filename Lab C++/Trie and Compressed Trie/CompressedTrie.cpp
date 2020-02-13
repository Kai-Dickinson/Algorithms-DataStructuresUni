#include "Trie.hpp"
#include "CompressedTrie.hpp"

CompressedTrie::CompressedTrie() {
    children = std::map<std::string, CompressedTrie*>();
}

CompressedTrie *CompressedTrie::compressTrie(Trie *t) {
    if (t == NULL) {
        return NULL;
    }
    CompressedTrie* newTrie = new CompressedTrie();

    
    for (int i = 0; i < 27; ++i) {
        if (t->children[i] != NULL) {
            std::string prefix = "a";
            prefix[0] += i;
            Trie* child = t->children[i];
            
            int nonNullCount = 0;
            int onlyChildInd = 0;
            
            do {
                nonNullCount = 0;
                onlyChildInd = 0;
                for (int j = 0; j < 27; ++j) {
                    if (child->children[j] != NULL) {
                        nonNullCount ++;
                        onlyChildInd = j;
                    }
                }
                if (nonNullCount == 1) {
                    prefix += onlyChildInd + 'a';
                    child = child->children[onlyChildInd];
                }
            } while (nonNullCount == 1);
            newTrie->children.insert(std::pair<std::string, CompressedTrie*>(prefix, compressTrie(child)));
        }
    }
    return newTrie;
}

bool CompressedTrie::query(std::string s) { //Check every substring and see if it is found, recurse on new substring and children
    return false;
}

void CompressedTrie::insert(std::string s) {
}
