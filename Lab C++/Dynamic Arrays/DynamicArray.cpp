#include "DynamicArray.hpp"

DynamicArray::DynamicArray(size_t size) {
    myArray = new int [size];
    arrayTotal = size;
    arrayLength = 0;
}

size_t DynamicArray::length() {
    return arrayLength;
}

int DynamicArray::select(size_t k) {
    return myArray[k];
}

void DynamicArray::store(int o, size_t k) {
    myArray[k] = o;
}

void DynamicArray::push(int o) {
    if (arrayLength < arrayTotal) {
        myArray[arrayLength] = o;
    } else {
        extend();
        myArray[arrayLength] = o;
    }
    arrayLength++;

}

int DynamicArray::pop() {
    arrayLength--;
    return myArray[arrayLength];
}

void DynamicArray::extend() {
    arrayTotal = arrayTotal * 2;
    int *tempArray = myArray;
    myArray = new int [arrayTotal];
    
    for (int j = 0; j < arrayLength; j++) {
        myArray[j] = tempArray[j];
    }
}
