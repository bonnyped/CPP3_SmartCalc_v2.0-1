// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_CALCULATOR_H_
#define SRC_CALCULATOR_H_

#include <cmath>
#include <functional>
#include <iostream>
#include <stack>
#include <vector>

#include "/home/bonnypedubuntu/21-school.ru/CPP3_SmartCalc_v2.0-1/src/token.h"

namespace s21 {
class Calculator {
 private:
  using value_type = double;
  using cvalue_reference = const double &;
  using stack_type = std::stack<value_type>;
  stack_type calc_result;

 public:
  Calculator() {}
  double calculate(const std::vector<s21::Token> &input);
  double applyAction(cvalue_reference left_operand,
                     cvalue_reference right_operand,
                     clexeme_reference operation);
};
}  // namespace s21

#endif  // SRC_CALCULATOR_H_
