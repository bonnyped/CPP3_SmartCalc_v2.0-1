// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "converter.h"

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
      unloadStackWhileLE(elem);
    else if (elem.getEntity() == EntityType::closeBracket)
      unloadStackBeforeOpenBracket();
  }
  fullUnloadStack();
  return getRpn();
}

void Converter::pushToRpn(ctoken_reference elem) { getRpn().push_back(elem); }
void Converter::pushToStack(ctoken_reference elem) { getStack().push(elem); }
void Converter::unloadStackWhileLE(ctoken_reference elem) {
  bool flag = false;
  while (!getStack().empty() &&
         getStack().top().getEntity() != EntityType::openBracket && !flag) {
    if (isTopStackFunction() || isTopStackOPerationGE(elem)) {
      getRpn().push_back(getStack().top());
      getStack().pop();
    } else {
      pushToStack(elem);
      flag = true;
    }
  }
  if (!flag) pushToStack(elem);
}

bool Converter::isTopStackFunction() {
  return getStack().top().getEntity() == EntityType::functions;
}

bool Converter::isTopStackOPerationGE(ctoken_reference elem) {
  return (getStack().top().getEntity() == EntityType::operations ||
          getStack().top().getEntity() == EntityType::unary_minus) &&
         getStack().top().getPriority() >= elem.getPriority();
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
    if (getStack().top().getEntity() == EntityType::openBracket)
      throw std::logic_error("Unpaired brackets");
    getRpn().push_back(getStack().top());
    getStack().pop();
  }
}

Converter::cvector_reference Converter::convertedResultForTest(
    cstring_reference input) {
  Token newElem{};
  for (size_type index = 0; index < input.size(); ++index) {
    if (isspace(input[index])) {
    } else if (isdigit(input[index])) {
      size_type shift = 0;
      double number = std::stod(&input[index], &shift);
      forTesting_.push_back(newElem);
      forTesting_.back().setNumber() = number;
      index += shift - 1;
    } else {
      forTesting_.push_back(newElem);
      forTesting_.back().setLexeme() = input[index];
    }
  }
  return forTesting_;
}

}  // namespace s21
