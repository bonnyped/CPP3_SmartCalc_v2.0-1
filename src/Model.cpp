// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "Model.h"

using namespace s21;

EntityType Model::determ(const char &currentChar) {
  EntityType res = EntityType::bad_charecter;
  if (isalpha(currentChar))
    res = EntityType::alphabetic;
  if (currentChar == '+')
    res = EntityType::plus;
  if (currentChar == '-')
    res = EntityType::minus;
  if (currentChar == '(')
    res = EntityType::openBracket;
  if (currentChar == ')')
    res = EntityType::closeBracket;
  else if (isdigit(currentChar))
    res = EntityType::numeric;
  // else if (currentChar == 32)
  //   res = EntityType::whitespace;
  return res;
};

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
