#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QWidget>
#include "mainwindow.h"
#include "../controller/controller_smart_calc.h"
#include "qcustomplot/qcustomplot.h"

namespace Ui {
class SmartCalc;
}
class SmartCalc : public QWidget
{
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

#endif // SMARTCALC_H
