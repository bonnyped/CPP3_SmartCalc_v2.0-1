// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_CALCULATOR_H_
#define SRC_CALCULATOR_H_

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
  double applyAction(cvalue_type left_operand,
                     cvalue_type right_operand,
                     clexeme_reference operation);
 public:
  Calculator() : calc_result_{} {}
  cvalue_type calculate(cvector_reference input, cvalue_type x_value);

  private:
  stack_type calc_result_;
};
}  // namespace s21

#endif  // SRC_CALCULATOR_H_
