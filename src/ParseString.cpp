// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "ParseString.h"

#include <iostream>

namespace s21 {
EntityType Parsing::determEntity(const char &currentChar) {
  EntityType entity = EntityType::bad_charecter;
  isdigit(currentChar)   ? entity = EntityType::numeric
  : isalpha(currentChar) ? entity = EntityType::alphabetic
                         : entity;
  return entity;
}

Parsing::vector_reference Parsing::convertToRpn() {
  for (size_type index = 0; index < getInputStr().size(); ++index) {
    EntityType curr = determEntity(getInputStr()[index]);
    curr == EntityType::numeric
        ? index = pushNumber(getInputSubStr(index), index)
        : index;
    if (curr == EntityType::alphabetic) {
      lexeme_type currLexeme = getInputStrChar(index);
      pushPrefixFunction(curr, currLexeme);
    }
    switch (getInputStr()[index]) {
      case '%':
        curr = EntityType::mod;
        break;
      case '+':
        curr = EntityType::plus;
        break;
      case '-':
        curr = EntityType::minus;
        break;
      case '*':
        curr = EntityType::mult;
        break;
      case '/':
        curr = EntityType::div;
        break;
      case '^':
        curr = EntityType::degree;
        break;
      case '(':
        curr = EntityType::openBracket;
        break;
      case ')':
        curr = EntityType::closeBracket;
        break;
      case 'x':
        curr = EntityType::xNum;
        break;
      default:
        // записать бяку
        break;
    }
  }
  return getRpn();
}

size_type Parsing::pushNumber(cstring_reference str, const size_type index) {
  size_type shift = 0;
  double number = std::stod(str, &shift);
  NumberToken toRpn(EntityType::numeric, number);
  getRpn().push_back(toRpn);
  shift += index - 1;
  return shift;
}

void Parsing::pushPrefixFunction(centity_type currEntity,
                                 clexeme_reference currentChar) {
  FunctionToken toStack(currEntity, currentChar);
  getStack().push(toStack);
}
};  // namespace s21
