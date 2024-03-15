// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "./test_smart_calc_cpp.h"

TEST(parser, test1) {
  std::string input =
      "- 12  -(-12   SIN(x)   -2+4modTaNG(-23)^ ATan(sin(x)))-24mod";
  s21::Coocker a(input);
  a.preparingStr();
  s21::Parser b(a.getStr());
  std::string expected_str = "~12-(~12s(x)-2+4%tg(~23)^n(s(x)))-24%";
  s21::Converter converter;
  std::vector<s21::Token> expected =
      converter.convertedResultForTest(expected_str);
  for (s21::size_type index = 0; index < expected.size(); ++index) {
    if (expected[index].getEntity() == s21::EntityType::numeric)
      EXPECT_TRUE(expected[index].getNumber() -
                      b.getPreRpn()[index].getNumber() <
                  s21_epsilon);
    else
      EXPECT_EQ(expected[index].getLexeme(), b.getPreRpn()[index].getLexeme());
  }
}

TEST(parser, test2) {
  std::string input = ",Hello .3f()%0-.5e+17";
  s21::Coocker a(input);
  a.preparingStr();
  s21::Parser b(a.getStr());
  std::string expected_str = "###ll#0.3#()%0-5e+16";
  s21::Converter converter;
  std::vector<s21::Token> expected =
      converter.convertedResultForTest(expected_str);
  for (s21::size_type index = 0; index < expected.size(); ++index) {
    if (expected[index].getEntity() == s21::EntityType::numeric)
      EXPECT_TRUE(expected[index].getNumber() -
                      b.getPreRpn()[index].getNumber() <
                  s21_epsilon);
    else
      EXPECT_EQ(expected[index].getLexeme(), b.getPreRpn()[index].getLexeme());
  }
}

TEST(parser, test3) {
  std::string input = "ACos(-1*.4)   / 19 mod 3.234234";
  s21::Coocker a(input);
  a.preparingStr();
  s21::Parser b(a.getStr());
  std::string expected_str = "a(~1*0.4)/19%3.23423";
  s21::Converter converter;
  std::vector<s21::Token> expected =
      converter.convertedResultForTest(expected_str);
  for (s21::size_type index = 0; index < expected.size(); ++index) {
    if (expected[index].getEntity() == s21::EntityType::numeric)
      EXPECT_TRUE(expected[index].getNumber() -
                      b.getPreRpn()[index].getNumber() <
                  s21_epsilon);
    else
      EXPECT_EQ(expected[index].getLexeme(), b.getPreRpn()[index].getLexeme());
  }
}

TEST(parser, test4) {
  std::string input =
      "ACos(-1*.4)   / 19 mod 3.234234 + sIN(X) ^ AtaN(x) * asiN(-x) ^ TAN(12) "
      "modacOS(1)";
  s21::Coocker a(input);
  a.preparingStr();
  s21::Parser b(a.getStr());
  std::string expected_str = "a(~1*0.4)/19%3.23423+s(x)^n(x)*i(~x)^t(12)%a(1)";
  s21::Converter converter;
  std::vector<s21::Token> expected =
      converter.convertedResultForTest(expected_str);
  for (s21::size_type index = 0; index < expected.size(); ++index) {
    if (expected[index].getEntity() == s21::EntityType::numeric)
      EXPECT_TRUE(expected[index].getNumber() -
                      b.getPreRpn()[index].getNumber() <
                  s21_epsilon);
    else
      EXPECT_EQ(expected[index].getLexeme(), b.getPreRpn()[index].getLexeme());
  }
}

TEST(parser, test5) {
  std::string input = "(1*(2+(3-(4/(5 ^ sin(11))))))-1    4";
  s21::Coocker a(input);
  a.preparingStr();
  s21::Parser b(a.getStr());
  s21::Parser x;
  std::string expected_str = "(1*(2+(3-(4/(5^s(11))))))-14";
  s21::Converter converter;
  std::vector<s21::Token> expected =
      converter.convertedResultForTest(expected_str);
  for (s21::size_type index = 0; index < expected.size(); ++index) {
    if (expected[index].getEntity() == s21::EntityType::numeric)
      EXPECT_TRUE(expected[index].getNumber() -
                      b.getPreRpn()[index].getNumber() <
                  s21_epsilon);
    else
      EXPECT_EQ(expected[index].getLexeme(), b.getPreRpn()[index].getLexeme());
  }
}

TEST(parser, test6) {
  std::string input =
      "ACos(-1.234E-23*.4827469234723974234234)   / 19.1231231 mod "
      "3.e12-234234";
  s21::Coocker a(input);
  a.preparingStr();
  s21::Parser b(a.getStr());
  std::string expected_str = "a(~1.234e-23*0.482747)/19.1231%3e+12-234234";
  s21::Converter converter;
  std::vector<s21::Token> expected =
      converter.convertedResultForTest(expected_str);
  for (s21::size_type index = 0; index < expected.size(); ++index) {
    if (expected[index].getEntity() == s21::EntityType::numeric)
      EXPECT_TRUE(expected[index].getNumber() -
                      b.getPreRpn()[index].getNumber() <
                  s21_epsilon);
    else
      EXPECT_EQ(expected[index].getLexeme(), b.getPreRpn()[index].getLexeme());
  }
}

TEST(parser, test7) {
  std::string input = "(1*(2+(3-(4/(5 ^ sin(11)))))-1    4";
  s21::Coocker a(input);
  a.preparingStr();
  s21::Parser b(a.getStr());
  s21::Converter converter;
  EXPECT_THROW(converter.convertToRpn(b.getPreRpn()), std::logic_error);
}
