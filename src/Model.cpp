// // "Copyright [2024] <bonnyped, tg: @ltybcrf>"

// #include "Model.h"

// char s21::Model::determAlphabetic(char *currentChar, size_type *outer_index)
// {
//   auto listFunc = std::array<std::string, 10>{
//       "acos", "asin", "atan", "cos", "ln", "log", "mod", "sqrt", "sin",
//       "tan"};
//   // acos(a), asin(i), atan(n), cos(c), ln(l),
//   // log(g),  mod(m), sqrt(q), sin(s), tan(t)
//   char result = 0;
//   size_type numElem = 0;
//   for (auto elem : listFunc) {
//     for (size_type index = 0; index < elem.size(); ++index) {
//       if (elem[index] != std::tolower(currentChar[index])) break;
//       if (index == elem.size() - 1) {
//         result = determLetter(numElem);
//         *outer_index += index;
//       }
//     }
//     ++numElem;
//   }
//   return result;
// }

// char s21::Model::determLetter(const size_type currentFunc) {
//   switch (currentFunc) {
//     case 0:
//       return 'a';
//     case 1:
//       return 'i';
//     case 2:
//       return 'n';
//     case 3:
//       return 'c';
//     case 4:
//       return 'l';
//     case 5:
//       return 'g';
//     case 6:
//       return 'm';
//     case 7:
//       return 'q';
//     case 8:
//       return 's';
//     case 9:
//       return 't';
//     default:
//       return 0;
//   }
// }

// void s21::Model::parseString(epnString Epn, epnString Stack) {
//   Priority currPriority = Priority::min;
//   char currChar = 0;
//   for (size_type index = 0; index < size(); ++index) {
//     currPriority = Priority::min;
//     // currChar = determCurrentPriorChar(&currPriority, &index, &Epn);
//     // validation();
//     checkStack(&Epn, &Stack, currChar, currPriority);
//   }
//   unloadStack(&Epn, &Stack);
//   printEpn(Epn);
// }

// // void s21::Model::validation() {}

// void s21::Model::checkingPriority(epnString *Epn, epnString *Stack,
//                                   const Priority currPriority) {
//   if (Stack->size()) {
//     while ((Stack->back().priority_ == Priority::pref ||
//             Stack->back().priority_ >= currPriority) &&
//            Stack->size() && Stack->back().priority_ < Priority::highest) {
//       Epn->push_back(Stack->back());
//       Stack->pop_back();
//     }
//   }
// }

// char s21::Model::determCurrentPriorChar(Priority *currPriority,
//                                         size_type *index, epnString *Epn) {
//   char currChar = 0;
//   switch (determEntity(data()[*index])) {
//     case EntityType::numeric: {
//       size_type numChar = 0;
//       double result = std::stod(&data()[*index], &numChar);
//       *currPriority = Priority::number;
//       Epn->push_back({0, *currPriority, result});
//       *index += numChar - 1;
//       break;
//     }
//     case EntityType::alphabetic:
//       currChar = determAlphabetic(&data()[*index], index);
//       currChar != 'm' ? *currPriority = Priority::pref : *currPriority;
//       break;
//     case EntityType::plus:
//       currChar = '+';
//       break;
//     case EntityType::minus:
//       currChar = '-';
//       break;
//     case EntityType::mult:
//       *currPriority = Priority::mid;
//       currChar = '*';
//       break;
//     case EntityType::div:
//       *currPriority = Priority::mid;
//       currChar = '/';
//       break;
//     case EntityType::degree:
//       *currPriority = Priority::max;
//       currChar = '^';
//       break;
//     case EntityType::openBracket:
//       *currPriority = Priority::highest;
//       currChar = '(';
//       break;
//     case EntityType::closeBracket:
//       *currPriority = Priority::highest;
//       currChar = ')';
//       break;
//     case EntityType::xNum:
//       Epn->push_back({'x', (*currPriority = Priority::number), 0});
//       break;
//     case EntityType::bad_charecter:
//       break;
//   }
//   return currChar;
// }

// void s21::Model::checkStack(epnString *Epn, epnString *Stack, char currChar,
//                             Priority currPriority) {
//   if (currPriority != Priority::number) {
//     if (currChar == ')') {
//       while (Stack->back().operation_ != '(') {
//         if (Stack->size() == 0) {
//           throw std::out_of_range("Incorrect number of brackets");
//         } else {
//           Epn->push_back({Stack->back().operation_, currPriority, 0});
//           Stack->pop_back();
//         }
//       }
//       if (Stack->back().operation_ == '(') Stack->pop_back();
//     } else if (currChar == '(') {
//       Stack->push_back({currChar, currPriority, 0});
//     } else {
//       checkingPriority(Epn, Stack, currPriority);
//       Stack->push_back({currChar, currPriority, 0});
//     }
//   }
// }

// void s21::Model::unloadStack(epnString *Epn, epnString *Stack) {
//   if (Stack->size() > 0) {
//     while (Stack->begin() != Stack->end()) {
//       Epn->push_back({Stack->back().operation_, Stack->back().priority_, 0});
//       Stack->pop_back();
//     }
//   }
// }

// void s21::Model::printEpn(const epnString &Epn) {
//   for (auto elem : Epn) {
//     if (elem.operation_ == 0)
//       std::cout << elem.operand_ << " ";
//     else
//       std::cout << elem.operation_ << " ";
//   }
// }
