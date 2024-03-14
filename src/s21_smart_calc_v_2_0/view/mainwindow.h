// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_S21_SMART_CALC_V_2_0_VIEW_MAINWINDOW_H_
#define SRC_S21_SMART_CALC_V_2_0_VIEW_MAINWINDOW_H_

#include <QMainWindow>

#include "../controller/smart_calc.h"
#include "creditcalc.h"
#include "depositcalc.h"
#include "smartcalc.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_radioButton_smart_calc_clicked();

  void on_radioButton_credit_calc_clicked();

  void on_radioButton_deposit_calc_clicked();

 private:
  Ui::MainWindow *ui;
  SmartCalc calc_;
  CreditCalc credit_calc_;
  DepositCalc deposit_calc_;
};

#endif  // SRC_S21_SMART_CALC_V_2_0_VIEW_MAINWINDOW_H_
