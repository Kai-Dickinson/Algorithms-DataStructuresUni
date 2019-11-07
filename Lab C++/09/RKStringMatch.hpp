#ifndef RKSTRINGMATCH_HPP
#define RKSTRINGMATCH_HPP

#include "StringMatch.hpp"

class RKStringMatch : public StringMatch {
public:
  size_t match(std::string, std::string) override;
  int CalcPattern(std::string pattlen);
  int TxtHash(std::string txtlen);
  char countingChar(std::string, int);
};

#endif
