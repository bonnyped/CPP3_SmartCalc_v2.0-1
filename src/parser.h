// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

#include <string>
#include <utility>
#include <vector>

#include "/home/bonnypedubuntu/21-school.ru/CPP3_SmartCalc_v2.0-1/src/token.h"

namespace s21 {
class Parser {
 private:
  using string_type = std::string;
  using string_pointer = string_type *;
  using string_reference = string_type &;
  using cstring_reference = const string_type &;
  using vector_type = std::vector<Token>;
  using vector_reference = vector_type &;
  vector_type pre_rpn_;
  EntityType determEntity(const char &currentChar);
  size_type pushNumber(cstring_reference str, csize_type index,
                       cmap_reference map);
  Token getToken(clexeme_reference currentChar, cmap_reference map);

 public:
  Parser() {}
  explicit Parser(cstring_reference input, const double xnum) { convertToPreRpn(input, xnum); }

  vector_reference convertToPreRpn(cstring_reference input, const double xnum);
  vector_reference getPreRpn() { return pre_rpn_; }
};
}  // namespace s21

#endif  //  SRC_PARSER_H_
