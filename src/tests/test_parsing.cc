// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "./test_smart_calc_cpp.h"

TEST(parsing, test_1) {
  s21::Coocker input("()");
  s21::Parser preparedString(input.preparingStr());
  try {
    s21::Validator validatedString(preparedString.getPreRpn());
  } catch (const std::exception& e) {
    EXPECT_STREQ(e.what(), "Error of sequence");
  }
}

TEST(parsing, test_1_1) {
  s21::Coocker input("(1))");
  s21::Parser preparedString(input.preparingStr());
  try {
    s21::Validator validatedString(preparedString.getPreRpn());
    s21::Converter convertedString(validatedString.getValidatedVector());
  } catch (const std::exception& e) {
    EXPECT_STREQ(e.what(), "Unpaired brackets");
  }
}

TEST(parsing, test_2) {
  std::string expected = "2 2 3 ^ ^";
  s21::size_type index = 0;
  s21::Coocker input("2^2^3");
  s21::Parser output(input.preparingStr());
  s21::Validator validatedString;
  s21::Converter convertedString;
  EXPECT_NO_THROW(validatedString.checkSequence(output.getPreRpn()));
  EXPECT_NO_THROW(
      convertedString.convertToRpn(validatedString.getValidatedVector()));
  std::vector<s21::Token> result =
      convertedString.convertedResultForTest(expected);
  for (auto elem : convertedString.getRpn())
    if (convertedString.getRpn().front().getEntity() ==
        s21::EntityType::numeric)
      EXPECT_EQ(elem.getNumber(), result[index++].getNumber());
    else
      EXPECT_EQ(elem.getLexeme(), result[index++].getLexeme());
}

TEST(parsing, test_3) {
  s21::size_type index = 0;
  std::string expected =
      "15 7 1 1 + - / 3 * 2 1 1 + + 15 * 7 200 1 + - / 3 * - 2 1 1 + + 15 7 1 "
      "1 + - / 3 * 2 1 1 + + - 15 7 1 1 + - / 3 * + 2 1 1 + + - * -";
  s21::Coocker input(
      "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
      "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))");
  s21::Parser output(input.preparingStr());
  s21::Validator validatedString;
  s21::Converter convertedString;
  EXPECT_NO_THROW(validatedString.checkSequence(output.getPreRpn()));
  EXPECT_NO_THROW(
      convertedString.convertToRpn(validatedString.getValidatedVector()));
  std::vector<s21::Token> result =
      convertedString.convertedResultForTest(expected);
  for (auto elem : convertedString.getRpn())
    if (convertedString.getRpn().front().getEntity() ==
        s21::EntityType::numeric)
      EXPECT_EQ(elem.getNumber(), result[index++].getNumber());
    else
      EXPECT_EQ(elem.getLexeme(), result[index++].getLexeme());
}

// (15/(7-(1+1))*3-(2+(1+1))  больше открывающихся скобок