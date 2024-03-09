// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_COOCKER_H_
#define SRC_COOCKER_H_

#include <map>
#include <string>

#include "./controller.h"

namespace s21 {
class Coocker {
 private:
  using value_type = std::string;
  using reference = value_type &;
  value_type inputStr_;

 public:
  Coocker() {}
  explicit Coocker(const value_type &rhs) : inputStr_(rhs) {}
  reference getStr() { return inputStr_; }
  void removeWhitespaces();
  void replaceMinus();
  void tolowerStr();
  void replaceFuncs();
  reference preparingStr();
};

class entitesMap {
 private:
  using value_type = std::string;
  using map_type = std::map<value_type, value_type>;
  map_type map_{{"acos", "a"}, {"asin", "i"}, {"atan", "n"}, {"cos", "c"},
                {"ln", "l"},   {"log", "g"},  {"mod", "%"},  {"sin", "s"},
                {"sqrt", "q"}, {"tan", "t"}};

 public:
  map_type &getMap() { return map_; }
};
};  // namespace s21

#endif  //  SRC_COOCKER_H_
