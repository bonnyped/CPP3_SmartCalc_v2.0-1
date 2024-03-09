// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "./s21_test_smart_calc_cpp.h"

TEST(parsing, test_1) {
  s21::Coocker input("())");
  s21::Parser output(input.preparingStr());
  EXPECT_THROW(output.convertToRpn(), std::logic_error);
}

TEST(parsing, test_2) {
  s21::size_type index = 0;
  s21::Coocker input("2^2^3");
  s21::Parser output(input.preparingStr());
  std::string expected("223^^");
  for (auto elem : output.getRpn())
    EXPECT_EQ(elem.getLexeme(), expected[index++]);
}

TEST(parsing, test_3) {
  s21::size_type index = 0;
  s21::Coocker input(
      "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
      "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))");
  s21::Parser output(input.preparingStr());
  std::string expected(
      "15711+~/3*211++15*72001+~/3*~211++15711+~/3*211++~15711+~/3*+211++~*~");
  for (auto elem : output.getRpn())
    EXPECT_EQ(elem.getLexeme(), expected[index++]);
}
