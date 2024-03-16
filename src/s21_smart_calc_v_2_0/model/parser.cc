// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "parser.h"

namespace s21 {
EntityType Parser::determEntity(const char &currentChar) {
  EntityType entity = EntityType::operations;
  isdigit(currentChar)   ? entity = EntityType::numeric
  : isalpha(currentChar) ? entity = EntityType::functions
  : currentChar == 'x'   ? entity = EntityType::xNum
                         : entity;
  return entity;
}

/*!
  \brief Функция проебразует строку в вектор токенов, определят сущность токена, обрабатывает числа с плавающей точки при помощи std:stod.

  Функция решает задачу дополнительной более детальной и углубленной подготовки выражения, к дальнейшей обработке.

  \return Вектор заполненных данными токенов. 
*/

Parser::vector_reference Parser::convertToPreRpn(cstring_reference input) {
  FillTokenMap map{};
  for (size_type index = 0; index < input.size(); ++index) {
    char currentChar = input[index];
    Token currentToken = getToken(currentChar, map.getMap());
    if (determEntity(currentChar) == EntityType::numeric || currentChar == '.')
      index = pushNumber(&input[index], index, map.getMap());
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

};  // namespace s21
