// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

/*!
  \file
  \brief Заголовочный файл класса заготовщика, который нужен для подготовки
  строки для последующей обработки. \author bonnyped \version 2.0 \date март
  2024 года \warning Пажалыстэ не душните, у меня дедлайн горит, поэтому
  возможно программа не работает или работает не до конца, а только до середины

  Данный класс решает следующие задачи:
  - удаление пробелов из входящей строки (необходимо для последующей корректной
  обработки строки)
  - замена в необходимых местах знаков "-" на знак "~" (унарный минус)
  - перевод симоволов в нижний регистр
  - замены название текстовых функций и оператора mod
*/

#ifndef SRC_S21_SMART_CALC_V_2_0_MODEL_COOCKER_H_
#define SRC_S21_SMART_CALC_V_2_0_MODEL_COOCKER_H_

#include <map>
#include <string>

namespace s21 {
class Coocker {
 private:
  using value_type = std::string;
  using reference = value_type &;
  void removeWhitespaces();
  void replaceMinus();
  void tolowerStr();
  void replaceFuncs();

 public:
  Coocker() {}
  explicit Coocker(const value_type &rhs) : input_str_(rhs) {}
  reference preparingStr();
  reference getStr() { return input_str_; }

 private:
  value_type input_str_;
};

class entitesMap {
 private:
  using value_type = std::string;
  using map_type = std::map<value_type, value_type>;
  using map_reference = map_type &;

 public:
  map_reference getMap() { return map_; }

 private:
  /*!
  \brief Карта-словарь, для замены строчных функций на литеры, для удобства
  дальнейшей обработки
  */
  map_type map_{{"acos", "a"}, {"asin", "i"}, {"atan", "n"}, {"cos", "c"},
                {"ln", "l"},   {"log", "g"},  {"mod", "%"},  {"sin", "s"},
                {"sqrt", "q"}, {"tan", "t"}};
};
}  // namespace s21

#endif  //  SRC_S21_SMART_CALC_V_2_0_MODEL_COOCKER_H_
