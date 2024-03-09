// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include "./token.h"

namespace s21 {
using string_type = std::string;
using vector_type = std::vector<Token>;
using stack_type = std::stack<Token>;

class Parser {
  using string_pointer = string_type *;
  using string_reference = string_type &;
  using cstring_reference = const string_type &;
  using vector_reference = vector_type &;
  using stack_reference = stack_type &;

 private:
  string_type inputStr_;
  vector_type PreRpn_;
  vector_type ReversePolishNotation_;
  stack_type Stack_;

 public:
  Parser() {}
  explicit Parser(const string_reference rhs) : Parser{} { inputStr_ = rhs; }

  EntityType determEntity(const char &currentChar);
  vector_reference convertToPreRpn();
  size_type pushNumber(cstring_reference str, csize_type index,
                       cmap_reference map);
  Token getToken(clexeme_reference currentChar, cmap_reference map);
  void pushOrStack(ctoken_reference currentToken);
  void unloadBeforeOpenBracket(Token toPush);
  void unloadBeforeLE(Token toPush);
  string_reference getInputStr() { return inputStr_; }
  const string_type getInputSubStr(const size_type index) {
    return &inputStr_[index];
  }
  lexeme_type getInputStrChar(const size_type index) {
    lexeme_type result = inputStr_.at(index);
    return result;
  }
  vector_reference getPreRpn() { return PreRpn_; }
  vector_reference getRpn() { return ReversePolishNotation_; }
  stack_reference getStack() { return Stack_; }
};
};  // namespace s21

#endif  //  SRC_PARSER_H_
