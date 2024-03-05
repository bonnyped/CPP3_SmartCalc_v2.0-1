// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_TOKEN_H_
#define SRC_TOKEN_H_

namespace s21 {
enum class EntityType : int8_t {
  bad_charecter,
  alphabetic,
  numeric,
  mod,
  plus,
  minus,
  mult,
  div,
  degree,
  openBracket,
  closeBracket,
  xNum
};

using size_type = std::size_t;
using number_type = double;
using number_pointer = number_type *;
using number_reference = number_type &;
using lexeme_type = char16_t;
using lexeme_pointer = lexeme_type *;
using lexeme_reference = lexeme_type &;
using clexeme_reference = const lexeme_type &;
using centity_type = const EntityType &;

class BaseToken {
 protected:
  EntityType entity_;
  number_pointer number_;
  lexeme_pointer lexeme_;

 public:
  BaseToken() : entity_{}, number_(nullptr), lexeme_(nullptr) {}

  int getEntity() { return static_cast<int>(entity_); }
  number_type getNumber() { return *number_; }
  lexeme_type getLexeme() { return *lexeme_; }
};

class NumberToken : public BaseToken {
 public:
  NumberToken() = default;
  NumberToken(const EntityType &entity, const number_reference rhs) {
    entity_ = entity;
    number_ = new number_type;
    *number_ = rhs;
    lexeme_ = nullptr;
  }
};

class FunctionToken : public BaseToken {
 public:
  FunctionToken() = default;
  FunctionToken(const EntityType &entity, clexeme_reference rhs) {
    entity_ = entity;
    number_ = nullptr;
    lexeme_ = new lexeme_type;
    *lexeme_ = rhs;
  }
};
};  // namespace s21

#endif  // SRC_TOKEN_H_
