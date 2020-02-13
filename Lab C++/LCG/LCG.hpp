#ifndef LCG_HPP
#define LCG_HPP

#include <cstdint>

class LCG {
public:
  LCG(uint64_t, uint64_t, uint64_t, uint64_t);
    uint64_t aVal;
    uint64_t cVal;
    uint64_t mVal;
    uint64_t theSeed;
    
    LCG(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);
    uint64_t bitShift;
    
  uint32_t next();
  void seed(uint64_t);
};

#endif
