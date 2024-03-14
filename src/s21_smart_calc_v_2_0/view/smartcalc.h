// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_S21_SMART_CALC_V_2_0_VIEW_SMARTCALC_H_
#define SRC_S21_SMART_CALC_V_2_0_VIEW_SMARTCALC_H_

#include <QWidget>

#include "../controller/smart_calc.h"
//#include "mainwindow.h"
#include "qcustomplot/qcustomplot.h"

namespace Ui {
class SmartCalc;
}
class SmartCalc : public QWidget {
  Q_OBJECT

 public:
  explicit SmartCalc(QWidget *parent = nullptr);
  ~SmartCalc();

  void makeGraph();
 private slots:
  void charEntity();
  void on_equalsButton_clicked();
  void on_delButton_clicked();
  void on_ACButton_clicked();
  void on_BuildGraph_clicked();

 private:
  void getDataFromView();
  void giveResultToView(const double result);
  void fillGraph(const std::vector<double> &x, const std::vector<double> &y);

 private:
  Ui::SmartCalc *ui;
  std::string input_string_from_view_;
  double x_;
  QCustomPlot *builded_graph_;
};

#endif  // SRC_S21_SMART_CALC_V_2_0_VIEW_SMARTCALC_H_
