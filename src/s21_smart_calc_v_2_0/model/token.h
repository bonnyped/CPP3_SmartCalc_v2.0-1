// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

/*!
  \file
  \brief Класс для сбора информации о текущей лексеме.
  \author bonnyped
  \version 2.0
  \date март 2024 года
  \warning Пажалыстэ не душните, у меня дедлайн горит, поэтому возможно
  программа не работает или работает не до конца, а только до середины

  Класс содержит в себе все необходимые для дальнешей работе с токенами
  информацией:
  - Тип сущности
  - Число (если токен не является числом, поле по умолчанию рвно 0)
  - Лескема (если токен является числом, а не лексемой, поле по умолчанию равно
  0)
  - Приоритетность (для операций и скобок)
  - Ассоциативность (для правоассоцитавных операций)
*/

#ifndef SRC_S21_SMART_CALC_V_2_0_MODEL_TOKEN_H_
#define SRC_S21_SMART_CALC_V_2_0_MODEL_TOKEN_H_

#include <map>

namespace s21 {
enum class EntityType : int8_t {
  functions,  ///< текущая токен - тригонометрическая функция
  numeric,    ///< текущий токен - число
  operations,   ///< текущий токен - операция
  unary_minus,  ///< текущий токен - унарный минус
  openBracket,  ///< текущий токен - открывающая скобка
  closeBracket,  ///< текущий токен - закрывающая скобка
  xNum,  ///< текущий токен - значение подставляемое вместо X
  bad,  ///< текущий токен - сущность любах других символов, попавших в строку.
        ///< По сути - ошибка
  first_sybol_in_string,  ///< это не токен, но сущность указывающая на то, что
                          ///< строка только началась (необходима для дальнейшей
                          ///< валидации данных)
  last_symbol_in_sytring  ///< аналогична предыдущей сущности, только
                          ///< противоположна
};
enum class Priority : int8_t {
  bad_symbol,  ///< дополнительно свидетельствует об ошибке введенных данных
  min,  ///< назначается для операций сложени и вычитания, а также взятию
        ///< остатка от деления
  mid,  ///< назначается для операций произведения и деления
  max,  ///< назначается для операции возведения в степень
  higest  ///< назначается для скобок, чтобы скобки не выталкивались из стэка
          ///< раньше времени
};
enum class Associativity : bool {
  left,  ///< всё максимально просто
  right  ///< и очевидно
};

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
  /*!
    \brief
    Геттер сущности
    \return сущность текущего токена
    */
  EntityType getEntity() const { return entity_; }
  /*!
    \brief
    Геттер числа
    \return число текущего токена
    */
  number_type getNumber() const { return number_; }
  /*!
    \brief
    Сеттер числа
    \return ссылку на число текущего токена
    */
  number_reference setNumber() { return number_; }
  /*!
    \brief
    Геттер лексемы
    \return константную ссылку на лексему текущего токена
    */
  clexeme_reference getLexeme() const { return lexeme_; }
  /*!
    \brief
    Сеттер лексемы
    \return ссылку на лексему текущего токена
    */
  lexeme_reference setLexeme() { return lexeme_; }
  /*!
    \brief
    Геттер приоритености
    \return ссылку на приоритетность текущего токена
    */
  cpriority_reference getPriority() const { return priority_; }
  /*!
    \brief
    Геттер ассоциативности
    \return ссылку на ассоциативность текущего токена
    */
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
  /*!
   \brief
   Геттер словаря, необходим для поиска по мапе, для последующего заполнения
   токенами выходного вектора
   */
  cmap_reference getMap() { return map_; }

 private:
  map_type map_{
      {{0, {EntityType::bad, 0, 35, Priority::bad_symbol, Associativity::left}},
       {1, {EntityType::numeric, 0, 0, Priority::min, Associativity::left}},
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
       {'x', {EntityType::xNum, 0, 'x', Priority::min, Associativity::left}}}};
};
}  // namespace s21

#endif  // SRC_S21_SMART_CALC_V_2_0_MODEL_TOKEN_H_
