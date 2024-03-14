// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_S21_SMART_CALC_V_2_0_MODEL_TOKEN_H_
#define SRC_S21_SMART_CALC_V_2_0_MODEL_TOKEN_H_

#include <map>

namespace s21 {
enum class EntityType : int8_t {
  functions,
  numeric,
  operations,
  unary_minus,
  openBracket,
  closeBracket,
  xNum,
  bad,
  first_sybol_in_string,
  last_symbol_in_sytring
};
enum class Priority : int8_t { bad_symbol, min, mid, max, higest, push };
enum class Associativity : bool { left, right };

using size_type = std::size_t;
using csize_type = const size_type;
using number_type = double;
using number_reference = number_type &;
using cnumber_reference = const number_type &;
using lexeme_type = char;
using lexeme_reference = lexeme_type &;
using clexeme_reference = const lexeme_type &;
using centity_reference = const EntityType &;
using priority_type = Priority;
using cpriority_reference = const Priority &;

class Token {
 public:
  Token() {}
  Token(EntityType entity, number_type number, lexeme_type lexeme,
        priority_type priority, Associativity associativity)
      : entity_(entity),
        number_(number),
        lexeme_(lexeme),
        priority_(priority),
        associativity_(associativity) {}
  EntityType getEntity() const { return entity_; }
  number_type getNumber() const { return number_; }
  number_reference setNumber() { return number_; }
  lexeme_reference setLexeme() { return lexeme_; }
  clexeme_reference getLexeme() const { return lexeme_; }
  cpriority_reference getPriority() const { return priority_; }
  Associativity getAssocitivity() const { return associativity_; }

 private:
  EntityType entity_{};
  number_type number_{};
  lexeme_type lexeme_{};
  priority_type priority_{};
  Associativity associativity_{};
};

using ctoken_reference = const Token &;
using map_type = std::map<char, Token>;
using cmap_reference = const map_type &;

class FillTokenMap {
 public:
  cmap_reference getMap() { return map_; }

 private:
  map_type map_{
      {{0, {EntityType::bad, 0, 35, Priority::bad_symbol, Associativity::left}},
       {1, {EntityType::numeric, 0, 0, Priority::push, Associativity::left}},
       {'a',
        {EntityType::functions, 0, 'a', Priority::max, Associativity::left}},
       {'i',
        {EntityType::functions, 0, 'i', Priority::max, Associativity::left}},
       {'n',
        {EntityType::functions, 0, 'n', Priority::max, Associativity::left}},
       {'c',
        {EntityType::functions, 0, 'c', Priority::max, Associativity::left}},
       {'l',
        {EntityType::functions, 0, 'l', Priority::max, Associativity::left}},
       {'g',
        {EntityType::functions, 0, 'g', Priority::max, Associativity::left}},
       {'s',
        {EntityType::functions, 0, 's', Priority::max, Associativity::left}},
       {'q',
        {EntityType::functions, 0, 'q', Priority::max, Associativity::left}},
       {'t',
        {EntityType::functions, 0, 't', Priority::max, Associativity::left}},
       {'%',
        {EntityType::operations, 0, '%', Priority::min, Associativity::left}},
       {'+',
        {EntityType::operations, 0, '+', Priority::min, Associativity::left}},
       {'-',
        {EntityType::operations, 0, '-', Priority::min, Associativity::left}},
       {'~',
        {EntityType::unary_minus, 0, '~', Priority::min, Associativity::left}},
       {'*',
        {EntityType::operations, 0, '*', Priority::mid, Associativity::left}},
       {'/',
        {EntityType::operations, 0, '/', Priority::mid, Associativity::left}},
       {'^',
        {EntityType::operations, 0, '^', Priority::max, Associativity::right}},
       {'(',
        {EntityType::openBracket, 0, '(', Priority::higest,
         Associativity::left}},
       {')',
        {EntityType::closeBracket, 0, ')', Priority::higest,
         Associativity::left}},
       {'x', {EntityType::xNum, 0, 'x', Priority::push, Associativity::left}}}};
};
}  // namespace s21

#endif  // SRC_S21_SMART_CALC_V_2_0_MODEL_TOKEN_H_
