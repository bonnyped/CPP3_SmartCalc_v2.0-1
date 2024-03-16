// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "../controller/credit.h"

namespace s21 {
void ControllerAnnuityCalc::calcResultInModel() {
  AnnuityCreditCalc calc_credit(from_view_);
  calc_credit.calcCreditData();
  from_model_ = calc_credit.getOutput();
}

void ControllerVariedCalc::calcResultInModel() {
  VariedCreditCalc calc_credit(from_view_);
  calc_credit.calcCreditData();
  from_model_ = calc_credit.getOutput();
}
}  // namespace s21
