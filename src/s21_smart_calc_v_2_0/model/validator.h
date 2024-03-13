// "Copyright [2024] <bonnyped, tg: @ltybcrf>"

#ifndef SRC_VALIDATOR_H_
#define SRC_VALIDATOR_H_

#include <map>
#include <stdexcept>
#include <utility>
#include <vector>

#include "parser.h"
#include "token.h"

namespace s21 {
class Validator {
 private:
  using vector_type = std::vector<Token>;
  using cvector_type = const vector_type;
  using cvector_reference = cvector_type &;

 public:
  Validator() {}
  explicit Validator(cvector_type input) { checkSequence(input); }
  void checkSequence(cvector_reference input);
  vector_type getValidatedVector() { return output_; }

  private:
  std::map<EntityType, std::vector<bool>> validatorMap_ = {
      {EntityType::first_sybol_in_string,
       {true, true, false, true, true, false, true, false}},
      {EntityType::functions,
       {false, false, false, false, true, false, false, false}},
      {EntityType::numeric,
       {false, false, true, false, false, true, false, false}},
      {EntityType::operations,
       {true, true, false, true, true, false, true, false}},
      {EntityType::unary_minus,
       {true, true, false, false, true, false, true, false}},
      {EntityType::openBracket,
       {true, true, false, true, true, false, true, false}},
      {EntityType::closeBracket,
       {false, false, true, false, false, true, true, false}},
      {EntityType::xNum,
       {false, false, true, false, false, true, false, false}},
      {EntityType::bad,
       {false, false, false, false, false, false, false, false}},
      {EntityType::last_symbol_in_sytring,
       {false, true, false, false, false, true, true, false}}
      /*func, num, oper,  unary, open,  close, xnum, bad */
  };
  vector_type output_;
};
}  // namespace s21

#endif  // SRC_VALIDATOR_H_
