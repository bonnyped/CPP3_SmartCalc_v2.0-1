// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "coocker.h"

#include <functional>

void s21::Coocker::removeWhitespaces() {
  auto it = std::remove_if(getStr().begin(), getStr().end(), isspace);
  getStr().erase(it, getStr().end());
}

void s21::Coocker::tolowerStr() {
  for (auto elem = getStr().begin(); elem != getStr().end(); ++elem)
    *elem = tolower(*elem);
}

void s21::Coocker::replaceFuncs() {
  s21::entitesMap Map;
  for (auto it = Map.getMap().begin(); it != Map.getMap().end(); ++it) {
    while (getStr().find(it->first) < getStr().size()) {
      getStr().replace(getStr().find(it->first), it->first.size(), it->second);
    }
  }
}

void s21::Coocker::replaceMinus() {
  for (auto it = getStr().begin(); it != getStr().end(); ++it) {
    if (*it == '-') {
      if (it == getStr().begin())
        *it = '~';
      else if (!isdigit(*(it - 1)) && *(it - 1) != ')' &&
               tolower(*(it - 1)) != 'e')
        *it = '~';
    }
  }
}

s21::Coocker::reference s21::Coocker::preparingStr() {
  removeWhitespaces();
  tolowerStr();
  replaceFuncs();
  replaceMinus();
  return getStr();
}
