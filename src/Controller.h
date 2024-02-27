// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

#include <iostream>

#include "Model.h"

class ExampleController {
private:
  s21::Model *model;

public:
  explicit ExampleController(s21::Model *m) : model(m) {}
};

#endif // SRC_CONTROLLER_H_

// double add(double a);
// double sub(double a);
// double mult(double a);
// double div(double a);
// void reset();