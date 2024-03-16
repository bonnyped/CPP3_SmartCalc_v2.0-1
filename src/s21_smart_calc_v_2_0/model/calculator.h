// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

/*!
  \file
  \brief Класс производящий подсчет выражения, используюзий вектор токенов
  преобразованный в обратную польскую нотацию, с использованием стэка. \author
  bonnyped \version 2.0 \date март 2024 года \warning Пажалыстэ не душните, у
  меня дедлайн горит, поэтому возможно программа не работает или работает не до
  конца, а только до середины

  Весь бэк находится в модели, взаимодействие модели с UI происходит через
  контроллер, и каждый класс модели отвечает за определнную задачу, подробнее о
  классах можно прочесть в блоках описания классов.
*/

#ifndef SRC_S21_SMART_CALC_V_2_0_MODEL_CALCULATOR_H_
#define SRC_S21_SMART_CALC_V_2_0_MODEL_CALCULATOR_H_

#include <cmath>
#include <functional>
#include <iostream>
#include <stack>
#include <vector>

#include "token.h"

namespace s21 {
class Calculator {
 private:
  using value_type = double;
  using cvalue_type = const double;
  using stack_type = std::stack<value_type>;
  using cvector_reference = const std::vector<s21::Token> &;
  value_type applyAction(cvalue_type left_operand, cvalue_type right_operand,
                         clexeme_reference operation);

 public:
  Calculator() : calc_result_{} {}
  double calculate(cvector_reference input, cvalue_type x_value);

 private:
  stack_type calc_result_;
};
}  // namespace s21

#endif  // SRC_S21_SMART_CALC_V_2_0_MODEL_CALCULATOR_H_
