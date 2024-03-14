// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_S21_SMART_CALC_V_2_0_VIEW_CREDITCALC_H_
#define SRC_S21_SMART_CALC_V_2_0_VIEW_CREDITCALC_H_

#include <QWidget>

#include "../model/model.h"

namespace Ui {
class CreditCalc;
}

class CreditCalc : public QWidget {
  Q_OBJECT

 public:
  explicit CreditCalc(QWidget *parent = nullptr);
  ~CreditCalc();

 private slots:
  void on_CalcCredit_clicked();

 private:
  Ui::CreditCalc *ui;
};

#endif  // SRC_S21_SMART_CALC_V_2_0_VIEW_CREDITCALC_H_
