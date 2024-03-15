// // "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "model.h"

#include "../controller/smart_calc.h"

namespace s21 {

void Model::determReversePolishNitation() {
  Coocker coocker(getInputedString());
  Parser parser{};
  Validator validator{};
  Converter converter{};
  coocker.preparingStr();
  parser.convertToPreRpn(coocker.getStr());
  validator.checkSequence(parser.getPreRpn());
  reverse_polish_notation_ =
      converter.convertToRpn(validator.getValidatedVector());
}

cvector_token_type Model::getReversePolishNitation() {
  return reverse_polish_notation_;
}

value_type Model::getResultForControllerOrGraph() {
  Calculator calculator{};
  return calculator.calculate(getReversePolishNitation(), getXValue());
}

void Model::fillVectorsForGraph() {
  value_type step = 0.2;
  Calculator calculator{};
  number_type max_x_value = 100000;
  number_type start = getXValue();
  number_type y = calculator.calculate(getReversePolishNitation(), start);
  x_.push_back(start);
  y_.push_back(y);
  while (start <= max_x_value) {
    start += step;
    y = calculator.calculate(getReversePolishNitation(), start);
    x_.push_back(start);
    y_.push_back(y);
  }
  max_x_value *= -1;
  start = 0;
  while (start >= max_x_value) {
    start -= step;
    y = calculator.calculate(getReversePolishNitation(), start);
    x_.push_back(start);
    y_.push_back(y);
  }
}
}  // namespace s21
