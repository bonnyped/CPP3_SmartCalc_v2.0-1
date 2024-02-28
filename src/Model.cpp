// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "Model.h"

using namespace s21;

EntityType Model::determEntity(const char &currentChar) {
  EntityType res = EntityType::bad_charecter;
  res = EntityType::alphabetic;
  if (currentChar == '+') res = EntityType::plus;
  if (currentChar == '-') res = EntityType::minus;
  if (currentChar == '(') res = EntityType::openBracket;
  if (currentChar == ')') res = EntityType::closeBracket;
  if (tolower(currentChar) == 'x') res = EntityType::xNum;

  return res;
}

char Model::determAlphabetic(char *currentChar, size_type *outer_index) {
  auto listFunc = std::array<std::string, 10>{
      "acos", "asin", "atan", "cos", "ln", "log", "mod", "sqrt", "sin", "tan"};
  // acos(a), asin(i), atan(n), cos(c), ln(l),
  // log(g),  mod(m), sqrt(q), sin(s), tan(t)
  char result = 0;
  size_type numElem = 0;
  for (auto elem : listFunc) {
    for (size_type index = 0; index < elem.size(); ++index) {
      if (elem[index] != currentChar[index]) break;
      if (index == elem.size() - 1) {
        result = determLetter(numElem);
        *outer_index += index;
      }
    }
    ++numElem;
  }
  return result;
}

char Model::determLetter(const size_type currentFunc) {
  switch (currentFunc) {
    case 0:
      return 'a';
    case 1:
      return 'i';
    case 2:
      return 'n';
    case 3:
      return 'c';
    case 4:
      return 'l';
    case 5:
      return 'g';
    case 6:
      return 'm';
    case 7:
      return 'q';
    case 8:
      return 's';
    case 9:
      return 't';
    default:
      return 0;
  }
}

// std::vector<std::string> s21::ExampleModel::split(const std::string &s
//                                                   // const std::regex
//                                                   &separator
// ) {
//   std::regex separ = std::regex{"[0-9]+"};
//   isalpha(s[0]) ? separ = std::regex{"[a-z]+"} : separ;
//   std::sregex_token_iterator iter(s.begin(), s.end(), separ, -1);
//   std::sregex_token_iterator end;
//   std::vector<std::string> a{iter, end};
//   // std::cout << *a.data() << '\n';
//   return {iter, end};
// }

// void ExampleModel::add(double a)
// {
//     data += a;
// }

// void ExampleModel::mult(double a)
// {
//     data *= a;
// }

// void ExampleModel::reset()
// {
//     data = 0;
// }
