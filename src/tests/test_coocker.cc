// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "./test_smart_calc_cpp.h"

TEST(coocker, test1) {
  std::string input =
      "    Hello, make this string delete     .fvs     spaces  ";
  s21::Coocker a(input);
  a.preparingStr();
  EXPECT_EQ("hello,makethisstringdelete.fvsspaces", a.getStr());
}

TEST(coocker, test2) {
  std::string input = "    --(-12-                              2+4-23)-24  ";
  s21::Coocker a(input);
  a.preparingStr();
  EXPECT_EQ("~~(~12-2+4-23)-24", a.getStr());
}

TEST(coocker, test3) {
  std::string input = "- 12  -(-12   HELLO  -2+4-23)-24";
  s21::Coocker a(input);
  a.preparingStr();
  EXPECT_EQ("~12-(~12hello~2+4-23)-24", a.getStr());
}

TEST(coocker, test4) {
  std::string input = "- 12  -(-12   SINES   -2+4ARCTaNGEns-23 ATan)-24mod";
  s21::Coocker a(input);
  a.preparingStr();
  EXPECT_EQ("~12-(~12ses~2+4arctgens~23n)-24%", a.getStr());
}

TEST(coocker, test5) {
  std::string input = "";
  s21::Coocker a(input);
  a.preparingStr();
  EXPECT_EQ("", a.getStr());
}
