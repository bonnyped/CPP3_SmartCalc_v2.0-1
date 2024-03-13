// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_COOCKER_H_
#define SRC_COOCKER_H_

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
   map_type map_{{"acos", "a"}, {"asin", "i"}, {"atan", "n"}, {"cos", "c"},
                 {"ln", "l"},   {"log", "g"},  {"mod", "%"},  {"sin", "s"},
                 {"sqrt", "q"}, {"tan", "t"}};
};
}  // namespace s21

#endif  //  SRC_COOCKER_H_
