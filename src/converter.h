// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_CONVERTER_H_
#define SRC_CONVERTER_H_

#include <stack>
#include <stdexcept>
#include <vector>

#include "/home/bonnypedubuntu/21-school.ru/CPP3_SmartCalc_v2.0-1/src/parser.h"

namespace s21 {
class Converter {
 private:
  using vector_type = std::vector<Token>;
  using vector_reference = vector_type &;
  using cvector_reference = const vector_type &;
  using stack_type = std::stack<Token>;
  using stack_reference = stack_type &;
  vector_type ReversePolishNotation_;
  stack_type Stack_;

 public:
  vector_type convertToRpn(cvector_reference input);
  void pushToRpn(ctoken_reference elem);
  void pushToStack(ctoken_reference elem);
  void unloadStackWhileLe(ctoken_reference elem);
  void unloadStackBeforeOpenBracket();
  void fullUnloadStack();
  vector_reference getRpn() { return ReversePolishNotation_; }
  stack_reference getStack() { return Stack_; }
};
}  // namespace s21

#endif  // SRC_CONVERTER_H_
