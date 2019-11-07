#include "LCG.hpp"

LCG::LCG(uint64_t _a, uint64_t _c, uint64_t _m, uint64_t seed) {
    aVal = _a;
    cVal = _c;
    mVal = _m;
    bitShift = 0;
    theSeed = seed;
}

LCG::LCG(uint64_t _a, uint64_t _c, uint64_t _m, uint64_t seed, uint64_t _shift) {
    aVal = _a;
    cVal = _c;
    mVal = _m;
    theSeed = seed;
    bitShift = _shift;
}

uint32_t LCG::next() {
    uint64_t currSeed = (aVal * theSeed + cVal) % mVal;
    seed(currSeed);
    currSeed = currSeed >> bitShift;
    return currSeed;

}

void LCG::seed(uint64_t seed) {
    theSeed = seed;
}
