// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "./s21_smart_calc_v_2_0/model/model.h"

using namespace s21;
using namespace std;

int main() {
  std::string input = "(1*(2+(3-(4/(5 ^ sin(11)))))-1    4";
  Coocker a(input);
  a.preparingStr();
  Parser b(a.getStr());
  Converter c;

  for (auto elem : b.getPreRpn()) {
    if (elem.getEntity() == EntityType::numeric)
      std::cout << elem.getNumber();
    else
      std::cout << elem.getLexeme();
  }
  
  std::cout << '\n';

  return 0;
}
