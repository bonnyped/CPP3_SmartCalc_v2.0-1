// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "./parser.h"

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
  // case EntityType::functions:
  //   pushOrStack(currentToken);
  //   break;
  // case EntityType::xNum:
  //   pushOrStack(currentToken);
  //   break;
  // case EntityType::operations:
  //   pushOrStack(currentToken);
  //   break;
  // }
  // if (!getStack().empty()) {
  //   while (!getStack().empty()) {
  //     if (getStack().top().getLexeme() == '(')
  //       throw std::logic_error("Unpaired brackets");
  //     getRpn().push_back(getStack().top());
  //     getStack().pop();
  //   }
  // }

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

void Parser::pushOrStack(ctoken_reference currentToken) {
  char currentChar = currentToken.getLexeme();
  currentChar == 'x'   ? getRpn().push_back(currentToken)
  : currentChar == ')' ? unloadBeforeOpenBracket(currentToken)
                       : unloadBeforeLE(currentToken);
}

void Parser::unloadBeforeOpenBracket(Token toPush) {
  if (toPush.getLexeme() == ')') {
    while (!getStack().empty() && getStack().top().getLexeme() != '(') {
      getRpn().push_back(getStack().top());
      getStack().pop();
    }
    !getStack().empty() && getStack().top().getLexeme() == '('
        ? getStack().pop()
        : throw std::logic_error("Unpaired brackets");
  }
}

void Parser::unloadBeforeLE(Token toPush) {
  bool skip = true;
  while (!getStack().empty() && getStack().top().getLexeme() != '(' &&
         getStack().top().getAssocitivity() != Associativity::right && skip) {
    if (getStack().top().getEntity() == EntityType::functions ||
        getStack().top().getPriority() >= toPush.getPriority()) {
      getRpn().push_back(getStack().top());
      getStack().pop();
    } else {
      skip = false;
    }
  }
  getStack().push(toPush);
}
};  // namespace s21
