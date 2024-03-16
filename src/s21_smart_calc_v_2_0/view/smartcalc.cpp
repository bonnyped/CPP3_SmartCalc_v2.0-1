// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#include "smartcalc.h"

#include <QMessageBox>
#include <QShowEvent>
#include <QVector>
#include <vector>

#include "mainwindow.h"
#include "ui_smartcalc.h"

SmartCalc::SmartCalc(QWidget *parent) : QWidget(parent), ui(new Ui::SmartCalc) {
  ui->setupUi(this);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_degree, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_open_br, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_close_br, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_unary_minus, SIGNAL(clicked()), this,
          SLOT(charEntity()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_x_number, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(charEntity()));
  connect(ui->equalsButton, SIGNAL(clicked()), this, SLOT(getInputString()));
  builded_graph_ = new QCustomPlot();
  ui->stackedWidgetqcustomplot->insertWidget(0, builded_graph_);
  ui->stackedWidgetqcustomplot->setCurrentIndex(0);
  makeGraph();
}

SmartCalc::~SmartCalc() {
  delete ui;
  delete builded_graph_;
}

void SmartCalc::charEntity() {
  QPushButton *currentCharEntity = (QPushButton *)sender();
  if (currentCharEntity->text() == "+/-")
    ui->textEdit->setText(ui->textEdit->text() + "-");
  else if (currentCharEntity->text() == "/")
    ui->textEdit->setText(ui->textEdit->text() + "/");
  else
    ui->textEdit->setText(ui->textEdit->text() + currentCharEntity->text());
}

void SmartCalc::on_equalsButton_clicked() {
  getDataFromView();
  s21::ControllerSmartCalc controller(input_string_from_view_, x_);
  try {
    giveResultToView(controller.getResult());
  } catch (std::exception &ex) {
    QMessageBox::critical(this, "error", ex.what());
  }
}

void SmartCalc::on_BuildGraph_clicked() {
  getDataFromView();
  s21::ControllerSmartCalc controller(input_string_from_view_, x_);
  try {
    controller.getResultForGraph();
  } catch (std::exception &ex) {
    QMessageBox::critical(this, "error", ex.what());
  }
  fillGraph(controller.getX(), controller.getY());
}

void SmartCalc::getDataFromView() {
  input_string_from_view_ = ui->textEdit->text().toStdString();
  x_ = ui->xValue->text().toDouble();
}

void SmartCalc::giveResultToView(const double result) {
  ui->resultCalc->setText(QString::number(result, 'g', 6));
}

void SmartCalc::fillGraph(const std::vector<double> &x,
                          const std::vector<double> &y) {
  QVector<double> x_(x.begin(), x.end());
  QVector<double> y_(y.begin(), y.end());

  builded_graph_->clearGraphs();
  builded_graph_->xAxis->setRange(ui->minX->value(), ui->maxX->value());
  builded_graph_->yAxis->setRange(ui->minY->value(), ui->maxY->value());
  builded_graph_->xAxis->setLabel("X");
  builded_graph_->yAxis->setLabel("y");
  builded_graph_->addGraph();
  builded_graph_->graph(0)->setData(x_, y_);
  builded_graph_->replot();
  builded_graph_->setInteraction(QCP::iRangeZoom, true);
  builded_graph_->setInteraction(QCP::iRangeDrag, true);
}

void SmartCalc::on_delButton_clicked() {
  QString temp = ui->textEdit->text();
  temp.chop(1);
  ui->textEdit->setText(temp);
}

void SmartCalc::on_ACButton_clicked() {
  ui->textEdit->setText("");
  ui->xValue->setText("");
  ui->resultCalc->setText("");
}

void SmartCalc::makeGraph() {
  QVector<double> x, y;

  x.push_back(-8);
  x.push_back(-6);
  x.push_back(-2);
  x.push_back(1);
  x.push_back(5);
  x.push_back(7);
  x.push_back(9);
  y.push_back(1);
  y.push_back(2);
  y.push_back(0);
  y.push_back(2);
  y.push_back(1);
  y.push_back(-4);
  y.push_back(-3);
  builded_graph_->xAxis->setRange(ui->minX->value(), ui->maxX->value());
  builded_graph_->yAxis->setRange(ui->minY->value(), ui->maxY->value());
  builded_graph_->addGraph();

  builded_graph_->graph(0)->setData(x, y);
  x.clear();
  y.clear();

  x.push_back(-3);
  x.push_back(0);
  x.push_back(3);
  x.push_back(5);
  x.push_back(9);
  y.push_back(6);
  y.push_back(8);
  y.push_back(7);
  y.push_back(5);
  y.push_back(7);
  builded_graph_->addGraph();
  builded_graph_->graph(1)->setData(x, y);
  x.clear();
  y.clear();
  x.push_back(1);
  x.push_back(3);
  x.push_back(3);
  x.push_back(3);
  x.push_back(4);
  x.push_back(5);
  x.push_back(6);
  x.push_back(6);

  y.push_back(2);
  y.push_back(7);
  y.push_back(9);
  y.push_back(10);
  y.push_back(11);
  y.push_back(11);
  y.push_back(10);
  y.push_back(9);

  builded_graph_->addGraph();
  builded_graph_->graph(2)->setData(x, y);
  x.clear();
  y.clear();
  x.push_back(6);
  x.push_back(5);
  x.push_back(4);
  x.push_back(3);
  y.push_back(9);
  y.push_back(8);
  y.push_back(8);
  y.push_back(9);
  builded_graph_->addGraph();
  builded_graph_->graph(3)->setData(x, y);
  x.clear();
  y.clear();
  QVector<double> xx = {4, 4.2, 4.3, 4.50, 4.7, 4.8, 5};
  QVector<double> yy = {9, 8.8, 8.7, 8.65, 8.7, 8.8, 9};
  x = xx;
  y = yy;
  builded_graph_->addGraph();
  builded_graph_->graph(4)->setData(x, y);
  x.clear();
  y.clear();
  x = {3.5, 3.7, 4, 4.3, 4.4};
  y = {10, 10.2, 10.3, 10.2, 10};
  builded_graph_->addGraph();
  builded_graph_->graph(5)->setData(x, y);
  x.clear();
  y.clear();
  x = {4.6, 4.7, 5, 5.3, 5.5};
  y = {10, 10.2, 10.3, 10.2, 10};
  builded_graph_->addGraph();
  builded_graph_->graph(6)->setData(x, y);
  x.clear();
  y.clear();
  builded_graph_->xAxis->setLabel("X - MAN");
  builded_graph_->yAxis->setLabel("y");
  builded_graph_->setInteraction(QCP::iRangeZoom,
                                 true);  // увеличение - уменьшение Графикa
  builded_graph_->setInteraction(QCP::iRangeDrag, true);  // передвинуть

  builded_graph_->replot();
}
