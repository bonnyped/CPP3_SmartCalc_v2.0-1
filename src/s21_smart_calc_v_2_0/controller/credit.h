// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_S21_SMART_CALC_V_2_0_CONTROLLER_CREDIT_H_
#define SRC_S21_SMART_CALC_V_2_0_CONTROLLER_CREDIT_H_

#include "../model/credit.h"
#include "../model/model.h"

namespace s21 {
class ControllerAnnuityCalc {
 public:
  ControllerAnnuityCalc() {}
  explicit ControllerAnnuityCalc(const Input &input)
      : from_view_(input), from_model_{} {}
  void calcResultInModel();
  const Output &getOutput() { return from_model_; }

 private:
  Input from_view_;
  Output from_model_;
};

class ControllerVariedCalc {
 public:
  ControllerVariedCalc() {}
  explicit ControllerVariedCalc(const Input &input)
      : from_view_(input), from_model_{} {}
  void calcResultInModel();
  const Output &getOutput() { return from_model_; }

 private:
  Input from_view_;
  Output from_model_;
};
}  // namespace s21

#endif  //  SRC_S21_SMART_CALC_V_2_0_CONTROLLER_CREDIT_H_
