// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_CONVERTER_H_
#define SRC_CONVERTER_H_

#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

#include "parser.h"

namespace s21 {
class Converter {
 private:
  using vector_type = std::vector<Token>;
  using vector_reference = vector_type &;
  using cvector_reference = const vector_type &;
  using stack_type = std::stack<Token>;
  using stack_reference = stack_type &;
  using string_type = std::string;
  using string_reference = string_type &;
  using cstring_reference = const string_type &;

  void pushToRpn(ctoken_reference elem);
  void pushToStack(ctoken_reference elem);
  void unloadStackWhileLE(ctoken_reference elem);
  bool isTopStackFunction();
  bool isTopStackOPerationGE(ctoken_reference elem);
  void unloadStackBeforeOpenBracket();
  void fullUnloadStack();
  stack_reference getStack() { return Stack_; }

 public:
  Converter() {}
  explicit Converter(cvector_reference input) { convertToRpn(input); }
  vector_type convertToRpn(cvector_reference input);
  vector_reference getRpn() { return ReversePolishNotation_; }
  cvector_reference convertedResultForTest(cstring_reference input);

 private:
  vector_type ReversePolishNotation_;
  vector_type forTesting_;
  stack_type Stack_;
};
}  // namespace s21

#endif  // SRC_CONVERTER_H_
