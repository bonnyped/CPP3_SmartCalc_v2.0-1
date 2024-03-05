// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "PreParse.h"

void s21::PreParse::removeWhitespaces() {
  auto it = std::remove_if(getStr().begin(), getStr().end(), isspace);
  getStr().erase(it, getStr().end());
}

void s21::PreParse::replaceMinus() {
  std::replace(getStr().begin(), getStr().end(), '-', '~');
}

void s21::PreParse::tolowerStr() {
  for (auto elem = getStr().begin(); elem != getStr().end(); ++elem)
    *elem = tolower(*elem);
}

void s21::PreParse::replaceFuncs() {
  s21::entitesMap Map;
  for (auto it = Map.getMap().begin(); it != Map.getMap().end(); ++it) {
    while (getStr().find(it->first) < getStr().size()) {
      getStr().replace(getStr().find(it->first), it->first.size(), it->second);
    }
  }
}

s21::PreParse::reference s21::PreParse::preparingStr() {
  removeWhitespaces();
  replaceMinus();
  tolowerStr();
  replaceFuncs();
  return getStr();
}

// void s21::PreParse::convertTokenToChar() {
//   entitesMap forReplace;
//   bool flag = false;
//   size_type beginLexem = 0;
//   size_type count = 0;
//   for (size_type index = 0; index < getStr().size(); ++index) {
//     if (!flag && isalpha(getStr().data()[index]) != false) {
//       beginLexem = index;
//       flag = true;
//     } else if (flag && isalpha(getStr().data()[index]) == false) {
//       count = index - beginLexem;
//     }
//     if (flag && count) {
//       std::cout << getStr().data() << '\n';
//       auto beg = getStr().begin() + beginLexem;
//       auto en = beg + count;
//       std::string src(beg, en);
//       getStr().replace(beginLexem, count, 2, forReplace[src].getLexem());
//       std::cout << getStr().data() << '\n';
//       flag = false;
//     }
//   }
// }
