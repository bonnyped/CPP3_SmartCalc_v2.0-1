// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_PARSESTRING_H_
#define SRC_PARSESTRING_H_

#include <stack>
#include <string>
#include <vector>

#include "Token.h"

namespace s21 {
using string_type = std::string;
using vector_type = std::vector<BaseToken>;
using stack_type = std::stack<BaseToken>;

struct fields {
  string_type inputStr_;
  vector_type ReversePolishNotation_;
  stack_type Stack_;
};

class Parsing {
  using string_pointer = string_type *;
  using string_reference = string_type &;
  using cstring_reference = const string_type &;
  using fields_reference = fields &;
  using vector_reference = vector_type &;
  using stack_reference = stack_type &;

 private:
  fields item;

 public:
  Parsing() {}
  explicit Parsing(const string_reference rhs) : Parsing{} {
    item.inputStr_ = rhs;
  }

  EntityType determEntity(const char &currentChar);
  vector_reference convertToRpn();
  size_type pushNumber(cstring_reference str, const size_type index);
  void pushPrefixFunction(centity_type currEntity,
                          clexeme_reference currentChar);

  string_reference getInputStr() { return item.inputStr_; }
  const string_type getInputSubStr(const size_type index) {
    return &item.inputStr_[index];
  }
  lexeme_type getInputStrChar(const size_type index) {
    lexeme_type result = item.inputStr_.at(index);
    return result;
  }
  vector_reference getRpn() { return item.ReversePolishNotation_; }
  stack_reference getStack() { return item.Stack_; }
};
};  // namespace s21

#endif  //  SRC_PARSESTRING_H_
