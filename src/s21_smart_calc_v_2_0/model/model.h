// "Copyright [2024] <bonnyped, tg: @ltybcrf>"
/*!
  \file
  \brief Это основной заголовочный файл модели в MVC проекта s21 Smart Calc
  \author bonnyped
  \version 2.0
  \date март 2024 года
  \warning Пажалыстэ не душните, у меня дедлайн горит, поэтому возможно
  программа не работает или работает не до конца, а только до середины

  Весь бэк находится в модели, взаимодействие модели с UI происходит через
  контроллер, и каждый класс модели отвечает за определнную задачу, подробнее о
  классах можно прочесть в блоках описания классов.
*/

#ifndef SRC_S21_SMART_CALC_V_2_0_MODEL_MODEL_H_
#define SRC_S21_SMART_CALC_V_2_0_MODEL_MODEL_H_

#include <algorithm>
#include <cctype>
#include <queue>
#include <string>
#include <vector>

#include "calculator.h"
#include "converter.h"
#include "coocker.h"
#include "credit.h"
#include "parser.h"
#include "token.h"
#include "validator.h"

namespace s21 {
using size_type = std::size_t;
using csize_type = const size_type;
using value_type = double;
using number_reference = value_type &;
using cvalue_type = const value_type;
using lexeme_type = char;
using lexeme_reference = lexeme_type &;
using clexeme_reference = const lexeme_type &;
using centity_reference = const EntityType &;
using priority_type = Priority;
using cpriority_reference = const Priority &;
using vector_type = std::vector<double>;
using cvector_reference = const vector_type &;
using vector_token_type = std::vector<s21::Token>;
using cvector_token_type = const vector_token_type &;

class Model {
 private:
  using value_type = double;
  using cvalue_type = const value_type;

 public:
  using reference = Model &;
  using string_type = std::string;
  using cstring_reference = const std::string &;
  Model() {}
  Model(cstring_reference input, cvalue_type x_value)
      : result_(),
        inputed_string_(input),
        x_value_(x_value),
        x_{},
        y_{},
        reverse_polish_notation_{} {}
  void determReversePolishNitation();
  value_type getResultForControllerOrGraph();
  string_type getInputedString() { return inputed_string_; }
  value_type getXValue() { return x_value_; }
  cvector_token_type getReversePolishNitation();
  void fillVectorsForGraph();
  cvector_reference getX() { return x_; }
  cvector_reference getY() { return y_; }

 private:
  value_type result_;
  string_type inputed_string_{};
  value_type x_value_;
  vector_type x_;
  vector_type y_;
  vector_token_type reverse_polish_notation_;
};
}  // namespace s21
#endif  // SRC_S21_SMART_CALC_V_2_0_MODEL_MODEL_H_
