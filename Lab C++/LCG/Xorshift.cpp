#include "Xorshift.hpp"

Xorshift::Xorshift(uint32_t _a, uint32_t _b, uint32_t _c, uint32_t seed) {
    aVal = _a;
    bVal = _b;
    cVal = _c;
    theSeed = seed;
}

uint32_t Xorshift::next() {
    // (y=y<<a; y=y>>b; y=y<<c).
    uint32_t y = theSeed;
    y ^= y << aVal;
    y ^= y >> bVal;
    y ^= y << cVal;
    
    
    seed(y);
    return y;
}

void Xorshift::seed(uint32_t seed) {
    theSeed = seed;
}
