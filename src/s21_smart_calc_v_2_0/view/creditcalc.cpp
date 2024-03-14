// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "./creditcalc.h"

#include "../controller/credit.h"
#include "./ui_creditcalc.h"

CreditCalc::CreditCalc(QWidget *parent)
    : QWidget(parent), ui(new Ui::CreditCalc) {
  ui->setupUi(this);
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::on_CalcCredit_clicked() {
  double loan_body = ui->doubleSpinLoanBody->value();
  int term = ui->spinBoxTermCredit->value();
  double interest = ui->doubleSpinInterestCredit->value();
  if (ui->radioButtonAnnuitete->isChecked()) {
    s21::ControllerAnnuityCalc annuitet_calc({loan_body, term, interest});
    annuitet_calc.calcResultInModel();
    ui->lineEditMonthlyPaymentResult->setText(QString::number(annuitet_calc.getOutput().max_monthly_pay_, 'f', 2));
    ui->lineEditOverpayResult->setText(QString::number(annuitet_calc.getOutput().overpayment_, 'f', 2));
    ui->lineEditTotalPaymentResult->setText(QString::number(annuitet_calc.getOutput().total_payment_, 'f', 2));
  } else {
    s21::ControllerVariedCalc varied_calc({loan_body, term, interest});
    varied_calc.calcResultInModel();
    QString max_min_pay = QString::number(varied_calc.getOutput().max_monthly_pay_, 'f', 2);
    max_min_pay += " ... ";
    max_min_pay += QString::number(varied_calc.getOutput().min_monthly_pay_, 'f', 2);
    ui->lineEditMonthlyPaymentResult->setText(max_min_pay);
    ui->lineEditOverpayResult->setText(QString::number(varied_calc.getOutput().overpayment_, 'f', 2));
    ui->lineEditTotalPaymentResult->setText(QString::number(varied_calc.getOutput().total_payment_, 'f', 2));
  }
}
