#ifndef SRC_CONTROLLER_SMART_CALC_
#define SRC_CONTROLLER_SMART_CALC_

#include <vector>
#include <string>
#include "../model/model.h"

namespace s21{
class ControllerSmartCalc {
public:
    ControllerSmartCalc(const std::string &input, const double x) : input_string_(input), calculated_result_{}, x_value_(x), x_{}, y_{} {}
    double getResult();
    void getResultForGraph();
    cvector_reference getX() {return x_;}
    cvector_reference getY() {return y_;}
    const double getXValue_() { return x_value_; }

private:
    private:
        std::string input_string_;
        double calculated_result_;
        double x_value_;
        vector_type x_;
        vector_type y_;
};
}

#endif //  SRC_CONTROLLER_SMART_CALC_
