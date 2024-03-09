// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "./console_view.h"

using namespace s21;
using namespace std;

int main() {
  std::string a;
  cout << "Введите данные для подсчета в калькуляторе:" << ' ';
  getline(cin, a);

  Coocker b(a);
  Parser c(b.preparingStr());

  c.convertToPreRpn();
  for (auto elem : c.getPreRpn()) {
    elem.getEntity() == EntityType::numeric ? std::cout << elem.getNumber()
                                            : std::cout << elem.getLexeme();
  }
  std::cout << '\n';
  Validator d;
  try {
    d.checkSequence(c.getPreRpn());
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  // std::cout << c.getRpn().back().getEntity() << '\n';

  return 0;
}
