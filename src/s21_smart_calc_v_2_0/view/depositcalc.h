// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_S21_SMART_CALC_V_2_0_VIEW_DEPOSITCALC_H_
#define SRC_S21_SMART_CALC_V_2_0_VIEW_DEPOSITCALC_H_

#include <QWidget>
namespace Ui {
class DepositCalc;
}

class DepositCalc : public QWidget {
  Q_OBJECT

 public:
  explicit DepositCalc(QWidget *parent = nullptr);
  ~DepositCalc();

 private:
  Ui::DepositCalc *ui;
};

#endif  // SRC_S21_SMART_CALC_V_2_0_VIEW_DEPOSITCALC_H_
