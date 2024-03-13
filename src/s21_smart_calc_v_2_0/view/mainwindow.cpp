#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_radioButton_smart_calc_clicked();
    this->setFixedSize(761, 584);
    ui->stackedWidget->setFixedSize(761,528);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_smart_calc_clicked()
{
    ui->stackedWidget->insertWidget(0, &calc_);
    ui->stackedWidget->setCurrentIndex(0);
    ui->radioButton_smart_calc->setChecked(true);
}


void MainWindow::on_radioButton_credit_calc_clicked()
{
    ui->stackedWidget->insertWidget(1, &credit_calc_);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_radioButton_deposit_calc_clicked()
{
    ui->stackedWidget->insertWidget(2, &deposit_calc_);
    ui->stackedWidget->setCurrentIndex(2);
}


