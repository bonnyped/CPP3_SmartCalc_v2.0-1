// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_PREPARSE_H_
#define SRC_PREPARSE_H_

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

#include "Model.h"

namespace s21 {
class PreParse {
 private:
  using value_type = std::string;
  using reference = value_type &;
  value_type inputStr_;

 public:
  PreParse() {}
  explicit PreParse(const value_type &rhs) : inputStr_(rhs) {}
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
  using map_type = std::map<value_type, std::string>;
  map_type map_{{"-", "~"},   {"acos", "a"}, {"asin", "i"}, {"atan", "n"},
                {"cos", "c"}, {"ln", "n"},   {"log", "g"},  {"mod", "%"},
                {"sin", "s"}, {"sqrt", "q"}, {"tan", "t"}};

 public:
  map_type &getMap() { return map_; }
};
};  // namespace s21

#endif  //  SRC_PREPARSE_H_

// std::map<value_type, PriorityToken> map_{
//       {"+", {"plus", '+', Priority::min}},
//       {"-", {"minus", '-', Priority::min}},
//       {"*", {"mult", '*', Priority::mid}},
//       {"/", {"div", '/', Priority::mid}},
//       {"^", {"degree", '^', Priority::max}},
//       {"(", {"open", '(', Priority::highest}},
//       {")", {"close", ')', Priority::highest}},
//       {"acos",  "a"},
//       {"asin",  "i"},
//       {"atan",  "n"},
//       {"cos", "c"},
//       {"ln" "n"},
//       {"log", "g"},
//       {"mod", "%"},
//       {"sin", "s"},
//       {"sqrt",  "q"},
//       {"tan", 't'}};