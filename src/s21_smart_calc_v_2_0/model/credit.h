// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

/*!
  \file
  \brief Содержит классы необходимый для рассчета показателей кредита
  \author bonnyped
  \version 2.0
  \date март 2024 года
  \warning Пажалыстэ не душните, у меня дедлайн горит, поэтому возможно
  программа не работает или работает не до конца, а только до середины
*/

#ifndef SRC_S21_SMART_CALC_V_2_0_MODEL_CREDIT_H_
#define SRC_S21_SMART_CALC_V_2_0_MODEL_CREDIT_H_

namespace s21 {

struct Input {
  double total_loan_amount_;
  int term_;
  double rate_of_interest_;
};

struct Output {
  double max_monthly_pay_;
  double min_monthly_pay_;
  double overpayment_;
  double total_payment_;
};

/*!
  \class
  \brief Класс кредитного калькулятора, умеет рассчитывать аннуитетный платеж
  \author bonnyped
  \version 2.0
  \date март 2024 года
  \warning Пажалыстэ не душните, у меня дедлайн горит, поэтому возможно
  программа не работает или работает не до конца, а только до середины
*/

class AnnuityCreditCalc {
 public:
  AnnuityCreditCalc() {}
  explicit AnnuityCreditCalc(const Input &input) : output_{} { input_ = input; }
  void calcCreditData();
  const Output &getOutput() { return output_; }

 private:
  Input input_;
  Output output_;
};

/*!
  \file
  \brief Класс кредитного калькулятора, умеет рассчитывать диффиренцированный
  платеж \author bonnyped \version 2.0 \date март 2024 года \warning Пажалыстэ
  не душните, у меня дедлайн горит, поэтому возможно программа не работает или
  работает не до конца, а только до середины
*/

class VariedCreditCalc {
 private:
  double s21_epsilon{1.e-7};

 public:
  explicit VariedCreditCalc(const Input &input) : output_{} { input_ = input; }
  void calcCreditData();
  const Output &getOutput() { return output_; }

 private:
  Input input_;
  Output output_;
};
}  // namespace s21

#endif  //  SRC_S21_SMART_CALC_V_2_0_MODEL_CREDIT_H_
