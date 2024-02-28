// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "./s21_test_smart_calc_cpp.h"

TEST(whitespaces, test_1) {
    std::string a = "     12312njl3kn24";
    s21::Model b(a);
    b.insertWhitespace();
    EXPECT_STREQ(b.c_str(), "     12312 njl 3 kn 24 ");
}

TEST(whitespaces, test_2) {
    std::string a = "1.23e-124kjbfv";
    s21::Model b(a);
    b.insertWhitespace();
    EXPECT_STREQ(b.c_str(), "1.23 e - 124 kjbfv");
}

TEST(whitespaces, test_3) {
    std::string a = "1 + 2 - jdfsvnl() * sin";
    s21::Model b(a);
    b.insertWhitespace();
    EXPECT_STREQ(b.c_str(), "1 + 2 - jdfsvnl ( ) * sin");
}

TEST(whitespaces, test_4) {
    std::string a = "1.234+182.2423-12,33";
    s21::Model b(a);
    b.insertWhitespace();
    EXPECT_STREQ(b.c_str(), "1.234 + 182.2423 - 12 , 33 ");
}

TEST(whitespaces, test_5) {
    std::string a = ".32423 + ljdvn23974nv4385.?";
    s21::Model b(a);
    b.insertWhitespace();
    EXPECT_STREQ(b.c_str(), ".32423 + ljdvn 23974 nv 4385.?");
}

TEST(whitespaces, test_6) {
    std::string a = "1h2j4k3k5l6";
    s21::Model b(a);
    b.insertWhitespace();
    EXPECT_STREQ(b.c_str(), "1 h 2 j 4 k 3 k 5 l 6 ");
}

TEST(whitespaces, test_7) {
    std::string a = "1............234+182..........2423-12,33";
    s21::Model b(a);
    b.insertWhitespace();
    EXPECT_STREQ(b.c_str(), "1............234 + 182..........2423 - 12 , 33 ");
}


