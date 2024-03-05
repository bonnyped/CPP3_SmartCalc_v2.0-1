// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "consoleView.h"

using namespace s21;
using namespace std;

int main() {
  std::string a;
  cout << "Введите данные для подсчета в калькуляторе:" << ' ';
  getline(cin, a);

  PreParse b(a);
  Parsing c(b.preparingStr());
  c.convertToRpn();
  double z = c.getRpn().back().getNumber();

  std::cout << z << '\n';
  std::cout << c.getRpn().back().getEntity() << '\n';

  return 0;
}
