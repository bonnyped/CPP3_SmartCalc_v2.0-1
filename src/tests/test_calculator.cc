// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "../s21_smart_calc_v_2_0/controller/smart_calc.h"
#include "./test_smart_calc_cpp.h"

TEST(calculator, test1) {
  s21::ControllerSmartCalc a(
      "ln ( 4 ) ^ 5 ^ 2 - 2 ^ 4 ^ 2 * 0.2 * ( - 0.3 ) * 0.1 * 0.1 * 0.6 / 456",
      0.0);
  EXPECT_DOUBLE_EQ(a.getResult(), 3518.7855793679746);
}

TEST(calculator, test2) {
  s21::ControllerSmartCalc a("55-Sin(23+4)/(45-2^2^2-Ln(6)+Log(6))/78", 0.0);
  EXPECT_DOUBLE_EQ(a.getResult(), 54.999561886007058);
}

TEST(calculator, test3) {
  s21::ControllerSmartCalc a("77 -77", 0.0);
  EXPECT_DOUBLE_EQ(a.getResult(), 0.0);
}

TEST(calculator, test4) {
  s21::ControllerSmartCalc a(".12e-11 - 0.12e-11", 0.0);
  EXPECT_DOUBLE_EQ(a.getResult(), 0.0);
}

TEST(calculator, test5) {
  s21::ControllerSmartCalc a("x^x+101", 3.0);
  EXPECT_DOUBLE_EQ(a.getResult(), 128.0);
}

TEST(calculator, test6) {
  s21::ControllerSmartCalc a("x^x^x", 2.0);
  EXPECT_DOUBLE_EQ(a.getResult(), 16.0);
}

TEST(calculator, test7) {
  s21::ControllerSmartCalc a("x^x^x^x", 2.0);
  EXPECT_DOUBLE_EQ(a.getResult(), 65536.0);
}

TEST(calculator, test8) {
  s21::ControllerSmartCalc a("2.12^2.12^1.234^4.234", 0.0);
  EXPECT_DOUBLE_EQ(a.getResult(), 108.35182084232704);
}

TEST(calculator, test9) {
  s21::ControllerSmartCalc a("tan(1)-sin(13)*2^3+sin(3)", 0.0);
  EXPECT_DOUBLE_EQ(a.getResult(), -1.6628085618983581);
}

TEST(calculator, test10) {
  s21::ControllerSmartCalc a("acos(-1)", 0.0);
  EXPECT_DOUBLE_EQ(a.getResult(), M_PI);
}

TEST(calculator, test11) {
  s21::ControllerSmartCalc a("acos(-1)+asin(1)+atan(1)+COS(1)-sqrt(12)", 0.0);
  EXPECT_DOUBLE_EQ(a.getResult(), 2.5739878345125229);
}

TEST(calculator, test12) {
  s21::ControllerSmartCalc a("15mod4", 0.0);
  EXPECT_DOUBLE_EQ(a.getResult(), 3.0);
}

TEST(calculator, test13) {
  s21::ControllerSmartCalc a("sin(x)", 1.0);
  s21::ControllerSmartCalc b("sin(x)", 1.0);
  a.getResultForGraph();
  b.getResultForGraph();
  for (s21::size_type index = 0; index < a.getX().size(); ++index)
    EXPECT_DOUBLE_EQ(a.getX()[index], b.getX()[index]);
  for (s21::size_type index = 0; index < a.getY().size(); ++index)
    EXPECT_DOUBLE_EQ(a.getY()[index], b.getY()[index]);
}

TEST(calculator, test14) {
  s21::ControllerSmartCalc a("77 / 0", 0.0);
  EXPECT_ANY_THROW(a.getResult());
}

TEST(calculator, test15) {
  s21::ControllerSmartCalc a("sqrt(-0.000000000000000000001)", 0.0);
  EXPECT_ANY_THROW(a.getResult());
}
