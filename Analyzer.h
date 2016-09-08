#ifndef ANALYZER_H
#define ANALYZER_H

/** @file Analyzer.h
 *  This is an analyzer header file.
 */

#include <iostream>
#include <stack>

#include "DataTypes.h"
#include "TokenMap.h"
#include "ErrorHandler.h"

/**
 * @brief The Analyzer class to analyzes sequence of characters
 * and finds out its state in terms of closed brackets
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
   */
  void AnalyzeString(std::string &a_inputString);

private:
  /**
   * @brief m_tokensStack - container for helping to analyzes sequence of characters
   */
  std::stack<Token_T> m_tokensStack;
  /**
   * @brief m_pos - current position in input line
   */
  int m_pos;
  /**
   * @brief m_strCount - number of current precessing line
   */
  int m_strCount;
  /**
   * @brief m_tokenMap - container for helping to analyzes sequence of characters
   */
  TokenMap m_tokenMap;
  /**
   * @brief m_errorHandler - errors handler
   */
  ErrorHandler m_errorHandler;
};

#endif // ANALYZER_H
