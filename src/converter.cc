// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "/home/bonnypedubuntu/21-school.ru/CPP3_SmartCalc_v2.0-1/src/converter.h"

namespace s21 {
Converter::vector_type Converter::convertToRpn(cvector_reference input) {
  for (auto elem : input) {
    if (elem.getEntity() == EntityType::numeric ||
        elem.getEntity() == EntityType::xNum)
      pushToRpn(elem);
    else if (elem.getEntity() == EntityType::functions ||
             elem.getEntity() == EntityType::openBracket ||
             elem.getLexeme() == '^')
      pushToStack(elem);
    else if (elem.getEntity() == EntityType::operations ||
             elem.getEntity() == EntityType::unary_minus)
      unloadStackWhileLe(elem);
    else if (elem.getEntity() == EntityType::closeBracket)
      unloadStackBeforeOpenBracket();
  }
  fullUnloadStack();
  return getRpn();
}

void Converter::pushToRpn(ctoken_reference elem) { getRpn().push_back(elem); }
void Converter::pushToStack(ctoken_reference elem) { getStack().push(elem); }
void Converter::unloadStackWhileLe(ctoken_reference elem) {
  while (!getStack().empty() &&
         getStack().top().getEntity() != EntityType::openBracket) {
    if (getStack().top().getEntity() == EntityType::functions ||
        ((getStack().top().getEntity() == EntityType::operations ||
          getStack().top().getEntity() == EntityType::unary_minus) &&
         getStack().top().getPriority() >= elem.getPriority())) {
      getRpn().push_back(getStack().top());
      getStack().pop();
    }
  }
  pushToStack(elem);
}

void Converter::unloadStackBeforeOpenBracket() {
  while (!getStack().empty() &&
         getStack().top().getEntity() != EntityType::openBracket) {
    getRpn().push_back(getStack().top());
    getStack().pop();
  }
  !getStack().empty() && getStack().top().getLexeme() == '('
      ? getStack().pop()
      : throw std::logic_error("Unpaired brackets");
}

void Converter::fullUnloadStack() {
  while (!getStack().empty()) {
    getRpn().push_back(getStack().top());
    getStack().pop();
  }
}

};  // namespace s21
