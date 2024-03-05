// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_MODEL_H_
#define SRC_MODEL_H_

#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "ParseString.h"
#include "PreParse.h"

namespace s21 {

// enum class Priority : int8_t { min, mid, max, pref, highest, number };

struct EpnString {
  char operation_;
  // Priority priority_;
  double operand_;
};

class Model : public std::string {
 public:
  // using size_type = std::size_t;
  using reference = Model &;
  using epnString = std::vector<EpnString>;

  // void parseString(epnString Epn, epnString Stack);
  // // void validation();
  // // void checkingPriority(epnString *Epn, epnString *Stack,
  // //                       const Priority currPriority);
  // EntityType determEntity(const char &currentChar);
  // char determAlphabetic(char *currentChar, size_type *index);
  // char determLetter(const size_type currentFunc);
  // // char determCurrentPriorChar(Priority *currPriority, size_type *index,
  // //                             epnString *Epn);
  // // void checkStack(epnString *Epn, epnString *Stack, char currChar,
  // //                 Priority currPriority);
  // void unloadStack(epnString *Epn, epnString *Stack);
  // void printEpn(const epnString &Epn);
};
};  // namespace s21

#endif  // SRC_MODEL_H_
