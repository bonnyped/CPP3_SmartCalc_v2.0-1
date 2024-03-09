// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_MODEL_H_
#define SRC_MODEL_H_

#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "/home/bonnypedubuntu/21-school.ru/CPP3_SmartCalc_v2.0-1/src/converter.h"
#include "/home/bonnypedubuntu/21-school.ru/CPP3_SmartCalc_v2.0-1/src/coocker.h"
#include "/home/bonnypedubuntu/21-school.ru/CPP3_SmartCalc_v2.0-1/src/validator.h"

namespace s21 {

class Model : public std::string {
 public:
  // using size_type = std::size_t;
  using reference = Model &;
  Model() {}

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
