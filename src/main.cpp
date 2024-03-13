// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "/home/bonnypedubuntu/21-school.ru/CPP3_SmartCalc_v2.0-1/src/controller.h"

using namespace s21;
using namespace std;

int main() {
  std::string a;
  cout << "Введите данные для подсчета в калькуляторе:" << ' ';
  getline(cin, a);

  Coocker b(a);
  Parser c(b.preparingStr());

  Validator d;
  Converter f;
  Calculator e;
  try {
    d.checkSequence(c.getPreRpn());
    f.convertToRpn(d.getValidatedVector());
    for (auto elem : f.getRpn()) {
      elem.getEntity() == EntityType::numeric ? std::cout << elem.getNumber()
                                              : std::cout << elem.getLexeme();
    }
    std::cout << '\n';
    e.calculate(f.getRpn());

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  // std::cout << c.getRpn().back().getEntity() << '\n';

  return 0;
}
