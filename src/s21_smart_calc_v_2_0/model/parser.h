// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

#include <string>
#include <utility>
#include <vector>

#include "token.h"

namespace s21 {
class Parser {
 private:
  using string_type = std::string;
  using string_pointer = string_type *;
  using string_reference = string_type &;
  using cstring_reference = const string_type &;
  using vector_type = std::vector<Token>;
  using vector_reference = vector_type &;
  EntityType determEntity(const char &currentChar);
  size_type pushNumber(cstring_reference str, csize_type index,
                       cmap_reference map);
  Token getToken(clexeme_reference currentChar, cmap_reference map);

 public:
  vector_reference convertToPreRpn(cstring_reference input);
  Parser() {}
  explicit Parser(cstring_reference input) { convertToPreRpn(input); }
  vector_reference getPreRpn() { return PreRpn_; }

  private:
  vector_type PreRpn_;
};
}  // namespace s21

#endif  //  SRC_PARSER_H_
