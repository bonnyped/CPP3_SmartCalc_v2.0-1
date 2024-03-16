// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

/*!
  \file
  \brief Класс пасрит строку в вектор токенов, попутно определяя сущность лексемы и ее необходимые свойства для дальнейшего перевода в обратную польскую нотацию и подсчета. 
  \author bonnyped
  \version 2.0
  \date март 2024 года
  \warning Пажалыстэ не душните, у меня дедлайн горит, поэтому возможно программа не работает или работает не до конца, а только до середины
*/

#ifndef SRC_S21_SMART_CALC_V_2_0_MODEL_PARSER_H_
#define SRC_S21_SMART_CALC_V_2_0_MODEL_PARSER_H_

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

  /*! 
    \brief Обычный геттер, преобразованной в вектор строки
   */
  vector_reference getPreRpn() { return PreRpn_; }

 private:
  vector_type PreRpn_;
};
}  // namespace s21

#endif  //  SRC_S21_SMART_CALC_V_2_0_MODEL_PARSER_H_
