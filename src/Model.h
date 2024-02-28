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
  closeBracket,
  xNum
};

using size_type = std::size_t;

class Model : public std::string {
 public:
  using reference = Model &;

  Model() noexcept {}
  explicit Model(const std::string &rhs) : std::string(rhs) {}

  void removeWhitespaces() {
    auto it = std::remove_if(begin(), end(), isspace);
    erase(it, end());
  }

  void parseString() {
    size_type numChar = 0;
    for (size_type index = 0; index < size(); ++index) {
      switch (determEntity(data()[index])) {
        case EntityType::numeric: {
          double result = std::stod(&data()[index], &numChar);
          index += numChar - 1;
          std::cout << "New res " << result << '\n';
          break;
        }
        case EntityType::alphabetic: {
          char result = determAlphabetic(&data()[index], &index);
          std::cout << "Here is the result ::::::::::   " << result << '\n';
        } break;
        case EntityType::plus:
          std::cout << '+' << '\n';
          break;
        case EntityType::minus:
          std::cout << '-' << '\n';
          break;
        case EntityType::openBracket:
          std::cout << '(' << '\n';
          break;
        case EntityType::closeBracket:
          std::cout << ')' << '\n';
          break;
        case EntityType::xNum:
          std::cout << 'x' << '\n';
          break;
        case EntityType::bad_charecter:
          break;
      }
    }
  }
  // Model() : std::string() {}
  // explicit Model(const Model &rhs) : std::string(rhs) {}

  EntityType determEntity(const char &currentChar);
  char determAlphabetic(char *currentChar, size_type *index);
  char determLetter(const size_type currentFunc);

  // bool pred(size_type index) {
  //   bool res = false;
  //   EntityType currEntity = determEntity(data()[index]);
  //   EntityType nextEntity = determEntity(data()[index + 1]);
  //   currEntity != nextEntity ? res = true : res;
  //   char currChar = data()[index];
  //   char nextChar = data()[index + 1];
  //   '.' != nextChar && '.' != currChar ? res = true : res;
  //   if (index) {
  //     char prevChar = data()[index - 1];
  //     (prevChar == 'e' || prevChar == 'E') &&
  //             (currChar == '-' || currChar == '+')
  //         ? res = false
  //         : res;
  //   }
  //   return res;
  // }

  // void epn() {
  //   size_type stop = size();
  //   EntityType curr = EntityType::bad_charecter;
  //   for (size_type index = 0; index < stop; ++index) {
  //     switch (determEntity(data()[index])) {
  //     case EntityType::whitespace:
  //       if (!index) {
  //         erase(begin());
  //         --stop;
  //         --index;
  //       } else if (curr == EntityType::numeric && index + 1 < stop &&
  //                  EntityType::numeric == determEntity(data()[index + 1])) {
  //         erase(begin() + index - 1);
  //         --stop;
  //         --index;
  //       }
  //       break;
  //     case EntityType::numeric:
  //       index = deleteWhitespacesNumbers(index);
  //       while (determEntity(data()[++index]) == EntityType::numeric) {
  //         std::cout << "numeric" << '\n';
  //         /* code */
  //       }

  //       break;

  //     default:
  //       break;
  //     }
  //   }
  // }
};
};  //  namespace s21

#endif  // SRC_MODEL_H_
