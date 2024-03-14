// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "./s21_smart_calc_v_2_0/model/model.h"

using namespace s21;
using namespace std;

int main() {
  VariedCreditCalc a({100000, 60, 15});

  a.calcCreditData();
  // std::cout << c.getRpn().back().getEntity() << '\n';

  return 0;
}
