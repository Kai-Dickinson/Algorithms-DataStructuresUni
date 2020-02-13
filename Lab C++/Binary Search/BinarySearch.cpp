#include "BinarySearch.hpp"

bool BinarySearch::search(int *array, int key, size_t lo, size_t hi)
{
    int midPoint = floorf((lo + hi - 1) / 2);
    
    if (lo == hi) {
        return false;
    } else if (array[midPoint] == key) {
        return true;
    } else if (key < array[midPoint]) {
        return search(array, key, lo, midPoint);
    } else {
        return search(array, key, midPoint+1, hi);
    }
}


int BinarySearch::count(int *array, int key, size_t lo, size_t hi)
{
    int midPoint = floorf((lo + hi - 1) / 2);
    
    if (lo == hi) {
        return counting;
    } else if (array[midPoint] == key) {
        counting += 1;
        int temp = counting;
        counting = 0;
        return temp;
    } else if (key < array[midPoint]) {
        counting += 1;
        return count(array, key, lo, midPoint);
    } else {
        counting += 1;
        return count(array, key, midPoint+1, hi);
    }
}




















