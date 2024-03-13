// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "/home/bonnypedubuntu/21-school.ru/CPP3_SmartCalc_v2.0-1/src/calculator.h"

namespace s21 {
Calculator::value_type Calculator::calculate(
    const std::vector<s21::Token>& input) {
  for (auto elem : input) {
    EntityType curr_elem = elem.getEntity();
    if (curr_elem == EntityType::numeric) {
      calc_result.push(elem.getNumber());
    } else if (curr_elem == EntityType::operations) {
      double right_operand = calc_result.top();
      std::cout << "right_operand: " << calc_result.top() << '\n';
      calc_result.pop();
      double left_operand = calc_result.top();
      std::cout << "left_operand: " << calc_result.top() << '\n';
      calc_result.top() =
          applyAction(left_operand, right_operand, elem.getLexeme());
      std::cout << "calc_result: " << calc_result.top() << '\n';
    } else if (curr_elem == EntityType::functions ||
               curr_elem == EntityType::unary_minus) {
      calc_result.top() = applyAction(0.0, calc_result.top(), elem.getLexeme());
      std::cout << "calc_result: " << calc_result.top() << '\n';
    }
  }
  return 0;
}

Calculator::value_type Calculator::applyAction(cvalue_reference left_operand,
                                               cvalue_reference right_operand,
                                               clexeme_reference operation) {
  value_type result = 0.0;
  const double pi = acos(-1);
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
      result = std::acos(right_operand) * 180 / pi;
      break;
    case 'i':
      result = std::asin(right_operand) * 180 / pi;
      break;
    case 'n':
      result = std::atan(right_operand) * 180 / pi;
      break;
    case 'c':
      result = std::cos(right_operand * pi / 180);
      break;
    case 'l':
      result = std::log(right_operand);
      break;
    case 'g':
      result = std::log10(right_operand);
      break;
    case 's':
      result = std::sin(right_operand * pi / 180);
      break;
    case 'q':
      result = std::sqrt(right_operand);
      break;
    case 't':
      result = std::tan(right_operand * pi / 180);
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
