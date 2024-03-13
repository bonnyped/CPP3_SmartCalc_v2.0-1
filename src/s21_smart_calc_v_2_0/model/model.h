// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_MODEL_H_
#define SRC_MODEL_H_

#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "calculator.h"
#include "converter.h"
#include "coocker.h"
#include "validator.h"

namespace s21 {
using size_type = std::size_t;
using csize_type = const size_type;
using number_type = double;
using number_reference = number_type &;
using cnumber_number_type = const number_type;
using lexeme_type = char;
using lexeme_reference = lexeme_type &;
using clexeme_reference = const lexeme_type &;
using centity_reference = const EntityType &;
using priority_type = Priority;
using cpriority_reference = const Priority &;
using vector_type = std::vector<double>;
using cvector_reference = const vector_type &;
using vector_token_type = std::vector<s21::Token>;
using cvector_token_type = const vector_token_type &;


class Model {
private:
    using value_type = double;
    using cvalue_type = const value_type;

 public:
     using reference = Model &;
     using string_type = std::string;
     using cstring_reference = const std::string &;
     Model() {}
     Model(cstring_reference input, cvalue_type x_value) : result_(), inputed_string_(input), x_value_(x_value), x_{}, y_{}, reverse_polish_notation_{} {}
     void determReversePolishNitation();
     cnumber_number_type getResultForControllerOrGraph();
     string_type getInputedString() {return inputed_string_;}
     value_type getXValue() {return x_value_;}
     cvector_token_type getReversePolishNitation();
     void fillVectorsForGraph();
     cvector_reference getX() {return x_;}
     cvector_reference getY() {return y_;}

  private:
     value_type result_;
     string_type inputed_string_{};
     value_type x_value_;
     vector_type x_;
     vector_type y_;
     vector_token_type reverse_polish_notation_;
};
}
#endif  // SRC_MODEL_H_
