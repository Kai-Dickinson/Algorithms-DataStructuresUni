#include "SLList.hpp"
#include "ListVisualiser.hpp"
#include <iostream>

ListVisualiser::ListVisualiser(SLList * a) {
    tempList = a;
}

void ListVisualiser::visualise() {
    for (int i = 0; i < tempList -> length(); i ++) {
        if (tempList -> nthRest(i) -> rest() != SLList::NIL) {
            std::cout << "[*|*] ->";
        } else {
            std::cout << "[*|/] \n";
        }
    }
    for (int j = 0; j < tempList -> length(); j ++) {
        std::cout << " |      ";
        
    }
    std::cout << "\n";
    for (int j = 0; j < tempList -> length(); j ++) {
        std::cout << " " + std::to_string(tempList -> nth(j)) + "     " ;
        
    }
}
