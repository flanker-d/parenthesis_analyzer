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
  void ClearTokenStack();
  void InitTokenStack();
  void InitAnalyzer();
  bool AnalyzeOpenParenthesis(TokenType_e a_type);
  bool AnalyzeCloseParenthesis(TokenType_e a_type);

public:
  Analyzer();
  void AnalyzeIt(std::string &input_string);
  void AnalyzeString(std::string &input_string);

private:
  std::stack<Token_T> m_stack;
  int m_pos;
  int m_str_count;
  TokenMap m_token_map;
};

#endif // ANALYZER_H
