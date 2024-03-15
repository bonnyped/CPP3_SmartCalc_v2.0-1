// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "../s21_smart_calc_v_2_0/model/credit.h"
#include "../s21_smart_calc_v_2_0/controller/credit.h"
#include "./test_smart_calc_cpp.h"

TEST(credit_calc, test1) {
  s21::AnnuityCreditCalc a({100000, 55, 33});
  a.calcCreditData();
  EXPECT_DOUBLE_EQ(std::floor(a.getOutput().max_monthly_pay_ * 100) / 100,
                   3547.95);
  EXPECT_DOUBLE_EQ(std::floor(a.getOutput().overpayment_ * 100) / 100,
                   95137.25);
  EXPECT_DOUBLE_EQ(std::floor(a.getOutput().total_payment_ * 100) / 100,
                   195137.25);
}

TEST(credit_calc, test2) {
  s21::VariedCreditCalc a({100000, 55, 33});
  a.calcCreditData();
  EXPECT_DOUBLE_EQ(std::floor(a.getOutput().max_monthly_pay_ * 100) / 100,
                   4568.18);
  EXPECT_DOUBLE_EQ(std::floor(a.getOutput().min_monthly_pay_ * 100) / 100,
                   1868.18);
  EXPECT_DOUBLE_EQ(std::floor(a.getOutput().overpayment_ * 100) / 100, 76999.990000000005);
  EXPECT_DOUBLE_EQ(std::floor(a.getOutput().total_payment_ * 100) / 100,
                   176999.98999999999);
}
