#include "HashTable.hpp"

HashTable::HashTable(long _a, long _c, long _m) {
    valA = _a;
    valC = _c;
    valM = _m;
    buckets = new int [valM]();
}

HashTable::~HashTable() {
}

//Uses the hashKey to find an index and try to insert the key into that position. If taken a loop begins to run across the length of the array, until it reaches the position it started at.
void HashTable::insert(int key) {
    int probingVal = 0;
    int hashKey = h(valA, valC, valM, key);
    bool dataAdded = false;
    
    if (buckets[hashKey] == 0) {
        buckets[hashKey] = key;
        dataAdded = true;
    } else {
        if (hashKey == (valM - 1)) {
            probingVal = 0;
        } else {
            probingVal = hashKey + 1;
        }
    }
    
    while ( (dataAdded == false) && (probingVal != hashKey) ) {
        if (buckets[probingVal] == 0) {
            buckets[probingVal] = key;
            dataAdded = true;
        } else {
            if (probingVal == (valM - 1)) {
                probingVal = 0;
            } else {
                probingVal ++;
            }
        }
    }
}

//Use key to get hashCode and find Index, then use same logic as insert to loop and check values after the index found to find the exact key value because hashCode could be same for two numbers.
bool HashTable::find(int key) {
    int probeNum = 0;
    int hashVal = h(valA, valC, valM, key);
    bool isFound = false;
    
    if (buckets[hashVal] == key) {
        isFound = true;
    } else {
        if (hashVal == (valM - 1)) {
            probeNum = 0;
        } else {
            probeNum = hashVal + 1;
        }
    }
    
    while ( (isFound == false) && (probeNum != hashVal) ) {
        if (buckets[probeNum] == key) {
            isFound = true;
        } else {
            if (probeNum == (valM - 1)) {
                probeNum = 0;
            } else {
                probeNum ++;
            }
        }
    }
    
    return isFound;
    
}

//Finds how many of the values are taken, returns as a fraction.
double HashTable::loadFactor() {
    double totalFraction;
    int totalTaken = 0;
    
    for (int i = 0; i < valM; i++) {
        if (buckets[i] != 0) {
            totalTaken ++;
        }
    }
    totalFraction = (float)totalTaken / (float)valM;
    
    return totalFraction;
}

int HashTable::h(long myA,long myC,long myM,int myIn) {
    return (((int)myA * myIn + (int)myC) % myM);
}

