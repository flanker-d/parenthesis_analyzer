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
  /**
   * @brief AnalyzeNextSymbol - Method processes next symbol of input string.
   * @param a_inputString - current string from standard input
   * @return success or fail
   */
  bool AnalyzeNextSymbol(std::string &a_inputString);

  /**
   * @brief InitTokenStack - Method initializations of the stack tokens.
   * Push the token "start of line" onto the stack.
   * Method must be executed before parsing a new line.
   */
  void InitTokenStack();

  /**
   * @brief InitAnalyzer - Method resets the counter of the current row position.
   * Method performs the initialization of the tokens stack.
   */
  void InitAnalyzer();

  /**
   * @brief PushOpenBracketToStack - Push open bracket token to stack
   * @param a_tokenType - token type
   * @return success
   */
  bool PushOpenBracketToStack(TokenType_e a_tokenType);

  /**
   * @brief AnalyzeCloseBracket - function parses the closing bracket token.
   * If top of stack has the necessary opening bracket token, then pop() this token.
   * @param a_tokenType - token type
   * @return success or fail
   */
  bool AnalyzeCloseBracket(TokenType_e a_tokenType);

public:
  /**
   * @brief Analyzer - class constructor
   */
  Analyzer();

  /**
   * @brief AnalyzeCurChar - method parses the current input symbol
   * @param a_inputString - current string from standard input
   * @return success or fail
   */
  bool AnalyzeCurChar(std::string &a_inputString);

  /**
   * @brief AnalyzeString - recursive analysis of input string
   * @param a_inputString - current string from standard input
   * @return success or fail
   */
  bool AnalyzeString(std::string &a_inputString);

private:
  std::stack<Token_T> m_tokensStack;
  int m_pos;
  int m_strCount;
  TokenMap m_tokensMap;
};

#endif // ANALYZER_H
