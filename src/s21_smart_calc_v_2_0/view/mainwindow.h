#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "smartcalc.h"
#include "creditcalc.h"
#include "depositcalc.h"
#include "../controller/controller_smart_calc.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
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
#endif // MAINWINDOW_H
