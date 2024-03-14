// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "../model/credit.h"

#include <cmath>

namespace s21 {
void AnnuityCreditCalc::calcCreditData() {
  double monthly_rate = input_.rate_of_interest_ / 12 / 100;
  double annuity_rate_ = monthly_rate *
                         std::pow(1 + monthly_rate, input_.term_) /
                         (std::pow(1 + monthly_rate, input_.term_) - 1);
  output_.max_monthly_pay_ =
      std::floor(input_.total_loan_amount_ * annuity_rate_ * 100) / 100;
  output_.min_monthly_pay_ = output_.max_monthly_pay_;
  output_.total_payment_ = output_.max_monthly_pay_ * input_.term_;
  output_.overpayment_ = output_.total_payment_ - input_.total_loan_amount_;
}

void VariedCreditCalc::calcCreditData() {
  double part_total_loan_amount = input_.total_loan_amount_ / input_.term_;
  double monthly_rate = 0.0;
  while (input_.total_loan_amount_ > 0) {
    monthly_rate = input_.total_loan_amount_ *
                   (input_.rate_of_interest_ / 100) * 30.416666 / 365;
    output_.max_monthly_pay_ > s21_epsilon
        ? output_.max_monthly_pay_
        : output_.max_monthly_pay_ = monthly_rate + part_total_loan_amount;
    output_.total_payment_ += monthly_rate + part_total_loan_amount;
    input_.total_loan_amount_ -= part_total_loan_amount;
    input_.total_loan_amount_ - (monthly_rate + part_total_loan_amount) <
            s21_epsilon
        ? output_.min_monthly_pay_ = monthly_rate + part_total_loan_amount
        : output_.min_monthly_pay_;
  }
  output_.overpayment_ =
      output_.total_payment_ - part_total_loan_amount * input_.term_;
}

}  // namespace s21
