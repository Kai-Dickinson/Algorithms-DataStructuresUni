#include "Heap.hpp"
#include <iostream>

unsigned int parent(unsigned int i) {
    float par = floorf((i - 1)/2);
    return par;
}

unsigned int left(unsigned int i) {
    float leftOne = 2 * i + 1;
    return leftOne;
}

unsigned int right(unsigned int i) {
    float rightOne = 2 * i + 2;
    return rightOne;
}
//------//

Heap::Heap(unsigned int len) {
    array.resize(len);
    heap_size = 0;
}

Heap::Heap(std::vector<int> source, bool incremental) {
    if (incremental == true) {
        array.clear();
        heap_size = 0;
        for (int i = 0; i < source.size(); ++i) {
            insert(source[i]);
        }
    } else {
        heap_size = source.size();
        array = source;
        buildMaxHeap();
    }
}

void Heap::maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    
    if ((l < heap_size) && (array[l] > array[largest])) {
        largest = l;
    }
    if ((r < heap_size) && (array[r] > array[largest])) {
        largest = r;
    }
    if (largest != i) {
        int numtemp = array[i];
        array[i] = array[largest];
        array[largest] = numtemp;
        maxHeapify(largest);
    }
    
}

void Heap::buildMaxHeap() {
    heap_size = array.size();
    for (int j = floor(array.size()/2); j >= 0 ; j--) {
        maxHeapify(j);
    }
}

int Heap::maximum() {
    return array[0];
}

void Heap::insert(int k) {
    array.push_back(k);
    int i = heap_size;
    heap_size += 1;
    while ((i > 0) && (array[parent(i)] < array[i])) {
        int num1 = array[i];
        int num2 = array[parent(i)];
        
        array[i] = num2;
        array[parent(i)] = num1;
        
        i = parent(i);
    }
}

int Heap::extractMax() {
    int max = array[0];
    array[0] = array[heap_size - 1];
    heap_size -= 1;
    maxHeapify(0);
    return max;
}

std::vector<int> Heap::sort() {
    buildMaxHeap();
    
    while (heap_size > 0) {
        int i = heap_size - 1;
        array[i] = extractMax();
    }
    return array;
}
