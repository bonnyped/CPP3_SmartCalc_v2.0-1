// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_S21_SMART_CALC_V_2_0_CONTROLLER_SMART_CALC_H_
#define SRC_S21_SMART_CALC_V_2_0_CONTROLLER_SMART_CALC_H_

#include <string>
#include <vector>

#include "../model/model.h"

namespace s21 {
class ControllerSmartCalc {
 public:
  ControllerSmartCalc(const std::string &input, const double x)
      : input_string_(input), calculated_result_{}, x_value_(x), x_{}, y_{} {}
  double getResult();
  void getResultForGraph();
  cvector_reference getX() const { return x_; }
  cvector_reference getY() const { return y_; }
  double getXValue_() { return x_value_; }

 private:
 private:
  std::string input_string_;
  double calculated_result_;
  double x_value_;
  vector_type x_;
  vector_type y_;
};
}  // namespace s21

#endif  //  SRC_S21_SMART_CALC_V_2_0_CONTROLLER_SMART_CALC_H_
