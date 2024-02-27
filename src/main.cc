// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include <regex>

#include "consoleView.h"

using namespace s21;

int main() {
  Model a;
  std::cout << "Введите данные для подсчета в калькуляторе:" << ' ';
  std::getline(std::cin, a);

  a.insertWhitespace();
  //    = "Hey12Im634here";
  size_type pos = 0;
  float z = std::stold(a.c_str(), &pos);
  std::cout << "HERE: " << z << " AND HERE: " << pos << '\n';
  // s21::size_type count = 0;

  std::cout << a << '\n';

  return 0;
}
