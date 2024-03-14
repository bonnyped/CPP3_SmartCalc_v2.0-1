// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "depositcalc.h"
#include "./ui_depositcalc.h"

DepositCalc::DepositCalc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepositCalc)
{
    ui->setupUi(this);
}

DepositCalc::~DepositCalc()
{
    delete ui;
}
