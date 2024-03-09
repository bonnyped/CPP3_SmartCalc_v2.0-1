// "Copyright [2023] <bonnyped, tg: @ltybcrf>"

#include "./console_view.h"

// std::string ConsoleView::getInputString() {
//   std::string inputString;
//   std::cout << "Input the expression: ";
//   std::cin >> inputString;
//   // std::cout << inputString << std::endl;
//   return inputString;
// }

// void ConsoleView::startEventLoop() {
//   while (true) {
//     double result;
//     displayMenu();
//     switch ((Choice)performChoice()) {
//       case SUM:
//         result = controller->add(performNumericInput());
//         break;

//       case SUB:
//         result = controller->sub(performNumericInput());
//         break;

//       case MUL:
//         result = controller->mult(performNumericInput());
//         break;

//       case DIV:
//         result = controller->div(performNumericInput());
//         break;

//       case RES:
//         controller->reset();
//         result = 0.0;
//         break;

//       case EXIT:
//         exit(1);

//       default:
//         std::cout << "Wrong menu item number!";
//         continue;
//     }

//     std::cout << "Current result is: " << result << std::endl;
//   }
// }

// void ConsoleView::displayMenu() {
//   std::cout << "=========" << '\n';
//   std::cout << " M E N U " << '\n';
//   std::cout << "=========" << '\n';
//   std::cout << "1. Add a number" << '\n';
//   std::cout << "2. Subtract a number" << '\n';
//   std::cout << "3. Multiplicate a number" << '\n';
//   std::cout << "4. Divide a number" << '\n';
//   std::cout << "5. Reset a number" << '\n';
//   std::cout << "0. Quit" << std::endl << '\n';
// }

// int ConsoleView::performChoice() {
//   int choice;
//   std::cout << "Input a menu item digit: ";
//   std::cin >> choice;
//   return choice;
// }
