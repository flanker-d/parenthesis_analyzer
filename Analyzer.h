#ifndef ANALYZER_H
#define ANALYZER_H

/** @file Analyzer.h
 *  This is an analyzer header file.
 */

#include <iostream>
#include <stack>

#include "DataTypes.h"
#include "TokenMap.h"

/**
 * @brief The Analyzer class
 */
class Analyzer
{
private:
  bool AnalyzeNextSymbol(std::string &input_string);
  void ClearTokenStack();
  void InitTokenStack();
  void InitAnalyzer();
  bool AnalyzeOpenParenthesis(TokenType_e a_type);
  bool AnalyzeCloseParenthesis(TokenType_e a_type);

public:
  Analyzer();
  bool AnalyzeIt(std::string &input_string);
  bool AnalyzeString(std::string &input_string);

private:
  std::stack<Token_T> m_stack;
  int m_pos;
  int m_str_count;
  TokenMap m_token_map;
};

#endif // ANALYZER_H
