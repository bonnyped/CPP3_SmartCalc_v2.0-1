// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "/home/bonnypedubuntu/21-school.ru/CPP3_SmartCalc_v2.0-1/src/parser.h"

namespace s21 {
EntityType Parser::determEntity(const char &currentChar) {
  EntityType entity = EntityType::operations;
  isdigit(currentChar)   ? entity = EntityType::numeric
  : isalpha(currentChar) ? entity = EntityType::functions
  : currentChar == 'x'   ? entity = EntityType::xNum
                         : entity;
  return entity;
}

Parser::vector_reference Parser::convertToPreRpn() {
  FillTokenMap map{};
  for (size_type index = 0; index < getInputStr().size(); ++index) {
    char currentChar = getInputStr()[index];
    // !index &&currentChar == '-' ? currentChar = '~' : currentChar;
    Token currentToken = getToken(currentChar, map.getMap());
    if (determEntity(currentChar) == EntityType::numeric || currentChar == '.')
      index = pushNumber(getInputSubStr(index), index, map.getMap());
    else
      getPreRpn().push_back(currentToken);
  }
  return getPreRpn();
}

size_type Parser::pushNumber(cstring_reference str, csize_type index,
                             cmap_reference map) {
  size_type shift = 0;
  double number = std::stod(str, &shift);
  Token toPush{map.find(1)->second};
  getPreRpn().push_back(toPush);
  getPreRpn().back().setNumber() = number;
  shift += index - 1;
  return shift;
}

Token Parser::getToken(clexeme_reference currentChar, cmap_reference map) {
  auto it = map.find(currentChar);
  return it != map.end() ? it->second : map.find(0)->second;
}

const std::string Parser::getInputSubStr(const size_type index) {
  return &inputStr_[index];
}

lexeme_type Parser::getInputStrChar(const size_type index) {
  lexeme_type result = inputStr_.at(index);
  return result;
}

};  // namespace s21
