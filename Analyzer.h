#ifndef ANALYZER_H
#define ANALYZER_H

#include <iostream>
#include <stack>

#include "data_types.h"

class Analyzer
{
private:
  void AnalyzeNextSymbol(std::string &input_string);
  void AnalyzeOpenParenthesis(states_e a_state);
  void AnalyzeCloseParenthesis(states_e a_state);

public:
  Analyzer();
  void AnalyzeIt(std::string &input_string);

private:
  states_e m_curState;
  std::stack<state_t> m_stack;
  int m_pos;
};

#endif // ANALYZER_H
