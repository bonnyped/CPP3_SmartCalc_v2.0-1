// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_MODEL_H_
#define SRC_MODEL_H_

#include <algorithm>
#include <cctype>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

namespace s21 {
enum class EntityType {
  bad_charecter,
  alphabetic,
  numeric,
  plus,
  minus,
  openBracket,
  closeBracket
};
using size_type = std::size_t;

class Model : public std::string {
public:
  using reference = Model &;

  explicit Model() noexcept {}
  explicit Model(const std::string &rhs) : std::string(rhs) {}

  void insertWhitespace() {
    for (size_type index = 0; index < size(); ++index) {
      if (pred1(index)) {
        insert(begin() + index + 1, 32);
      }
    }
  }
  // Model() : std::string() {}
  // explicit Model(const Model &rhs) : std::string(rhs) {}

  EntityType determ(const char &currentChar);
  bool pred1(size_type index) {
    return determ(data()[index]) != determ(data()[index + 1]) &&
           32 != data()[index + 1] && 32 != data()[index] &&
           46 != data()[index + 1] && 46 != data()[index];
  }
};

}; //  namespace s21

#endif // SRC_MODEL_H_
