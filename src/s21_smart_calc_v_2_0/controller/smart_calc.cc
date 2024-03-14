#include "smart_calc.h"

namespace s21{
double ControllerSmartCalc::getResult() {
    if(input_string_.size()){
        Model model(input_string_, x_value_);
        model.determReversePolishNitation();
        calculated_result_ = model.getResultForControllerOrGraph();
    }
    return calculated_result_;
}

void ControllerSmartCalc::getResultForGraph(){
    if(input_string_.size()){
        Model model(input_string_, x_value_);
        model.determReversePolishNitation();
        model.fillVectorsForGraph();
        x_ = model.getX();
        y_ = model.getY();
    }
}
}
