// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "coocker.h"

#include <functional>

/*!
  \file
  \author bonnyped
  \version 2.0
  \date март 2024 года
  \warning Пажалыстэ не душните, у меня дедлайн горит, поэтому возможно
  программа не работает или работает не до конца, а только до середины
*/

namespace s21 {
void Coocker::removeWhitespaces() {
  auto it = std::remove_if(getStr().begin(), getStr().end(), isspace);
  getStr().erase(it, getStr().end());
}

void removeMoreThanOnePoint();

void Coocker::tolowerStr() {
  for (auto elem = getStr().begin(); elem != getStr().end(); ++elem)
    *elem = tolower(*elem);
}

void Coocker::replaceFuncs() {
  entitesMap Map;
  for (auto it = Map.getMap().begin(); it != Map.getMap().end(); ++it) {
    while (getStr().find(it->first) < getStr().size()) {
      getStr().replace(getStr().find(it->first), it->first.size(), it->second);
    }
  }
}

void Coocker::replaceMinus() {
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
/*!
  \brief  функция применяет скрытые методы класса Coocker

  \return подготовленную для дальнейшей обработки строку
*/
Coocker::reference Coocker::preparingStr() {
  removeWhitespaces();
  tolowerStr();
  replaceFuncs();
  replaceMinus();
  return getStr();
}
}  // namespace s21
