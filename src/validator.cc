// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "/home/bonnypedubuntu/21-school.ru/CPP3_SmartCalc_v2.0-1/src/validator.h"

namespace s21 {
void Validator::checkSequence(const vector_type &input) {
  EntityType prev = EntityType::first_sybol_in_string;
  EntityType curr = prev;
  int8_t check = 1;
  for (auto it = input.begin(); it != input.end(); ++it) {
    curr = it->getEntity();
    it == input.end() - 1 ? check = 2 : check;
    for (auto number_of_check = 0; number_of_check < check; ++number_of_check) {
      !validatorMap_.find(prev)->second.at(static_cast<size_type>(curr))
          ? throw std::logic_error("Error of sequence")
          : prev = (check == 2 ? EntityType::last_symbol_in_sytring : curr);
    }
  }
  output_ = input;
}

}  // namespace s21
