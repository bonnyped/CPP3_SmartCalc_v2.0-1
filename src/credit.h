// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_CREDIT_H_
#define SRC_CREDIT_H_

#include <ostream>

#include "model.h"

namespace s21 {
  
struct Input {
  double total_loan_amount_;
  int term_;
  double rate_of_interest_;
};

struct Output {
  double max_monthly_pay_;
  double min_monthly_pay_;
  double overpayment_;
  double total_payment_;
};

class AnnгityCreditCalc {
 public:
  explicit AnnгityCreditCalc(const Input &input) : output_{} { input_ = input; }
  void calcCreditData();

 private:
  Input input_;
  Output output_;
};

class VariedCreditCalc {
 private:
  double s21_epsilon{1.e-7};

 public:
  explicit VariedCreditCalc(const Input &input) : output_{} { input_ = input; }

  void calcCreditData();

 private:
  Input input_;
  Output output_;
};
}  // namespace s21

#endif  //  SRC_CREDIT_H_
