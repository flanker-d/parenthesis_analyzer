#ifndef ANALYZER_H
#define ANALYZER_H

#include <iostream>
#include <stack>

#include "data_types.h"
#include "TokenMap.h"

class Analyzer
{
private:
  void AnalyzeNextSymbol(std::string &input_string);
  bool AnalyzeOpenParenthesis(ParenthesisType_e a_type);
  bool AnalyzeCloseParenthesis(ParenthesisType_e a_type);

public:
  Analyzer();
  void AnalyzeIt(std::string &input_string);

private:
  states_e m_curState;
  std::stack<Token_T> m_stack;
  int m_pos;
  TokenMap m_token_map;
};

#endif // ANALYZER_H
