// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "calculator.h"

namespace s21 {
Calculator::value_type Calculator::calculate(cvector_reference input,
                                             cvalue_type x_value) {
  for (auto elem : input) {
    EntityType curr_elem = elem.getEntity();
    if (curr_elem == EntityType::numeric) {
      calc_result_.push(elem.getNumber());
    } else if (curr_elem == EntityType::operations) {
      double right_operand = calc_result_.top();
      calc_result_.pop();
      double left_operand = calc_result_.top();
      calc_result_.top() =
          applyAction(left_operand, right_operand, elem.getLexeme());
    } else if (curr_elem == EntityType::xNum) {
      calc_result_.push(x_value);
    } else if (curr_elem == EntityType::functions ||
               curr_elem == EntityType::unary_minus) {
      calc_result_.top() =
          applyAction(0.0, calc_result_.top(), elem.getLexeme());
    }
  }
  return calc_result_.top();
}

Calculator::value_type Calculator::applyAction(cvalue_type left_operand,
                                               cvalue_type right_operand,
                                               clexeme_reference operation) {
  value_type result = 0.0;
  std::negate<value_type> neg;
  switch (operation) {
    case '+':
      result = left_operand + right_operand;
      break;
    case '-':
      result = left_operand - right_operand;
      break;
    case '*':
      result = left_operand * right_operand;
      break;
    case '/':
      result = left_operand / right_operand;
      break;
    case '^':
      result = std::pow(left_operand, right_operand);
      break;
    case '%':
      result = std::fmod(left_operand, right_operand);
      break;
    case 'a':
      result = std::acos(right_operand);
      break;
    case 'i':
      result = std::asin(right_operand);
      break;
    case 'n':
      result = std::atan(right_operand);
      break;
    case 'c':
      result = std::cos(right_operand);
      break;
    case 'l':
      result = std::log(right_operand);
      break;
    case 'g':
      result = std::log10(right_operand);
      break;
    case 's':
      result = std::sin(right_operand);
      break;
    case 'q':
      result = std::sqrt(right_operand);
      break;
    case 't':
      result =
          std::tan(right_operand);  // неправильный график получается как будто
      break;
    case '~':
      result = neg(right_operand);
      break;
    default:
      break;
  }
  return result;
}
}  // namespace s21
