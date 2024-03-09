// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "/home/bonnypedubuntu/21-school.ru/CPP3_SmartCalc_v2.0-1/src/console_view.h"

using namespace s21;
using namespace std;

int main() {
  std::string a;
  cout << "Введите данные для подсчета в калькуляторе:" << ' ';
  getline(cin, a);

  Coocker b(a);
  Parser c(b.preparingStr());

  c.convertToPreRpn();
  Validator d;
  Converter f;
  try {
    d.ValidateVector(c.getPreRpn());
    f.convertToRpn(d.getValidatedVector());
    for (auto elem : f.getRpn()) {
      elem.getEntity() == EntityType::numeric ? std::cout << elem.getNumber()
                                              : std::cout << elem.getLexeme();
    }
    std::cout << '\n';

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  // std::cout << c.getRpn().back().getEntity() << '\n';

  return 0;
}
