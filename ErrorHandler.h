#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include "DataTypes.h"
#include "TokenMap.h"
#include <iostream>

/**
 * @brief The ErrorHandler class processes analisis errors and successes,
 * and prints diagnostics informations
 */
class ErrorHandler
{
public:

  /**
   * @brief ProcessError - Method handles analyze error, then prints result
   * @param a_lastStackToken - last token in token-stack
   * @param a_curTokenType - current token to handling
   * @param a_curLineNumber - current number of input line
   * @param a_curPos - current position in line to handling
   */
  void ProcessError(Token_T &a_lastStackToken, TokenType_e a_curTokenType, int a_curLineNumber, int a_curPos);

  /**
   * @brief ProcessSuccess - Method handles analyze success
   * @param a_curLineNumber - current number of input line
   */
  void ProcessSuccess(int a_curLineNumber);

private:
  /**
   * @brief m_tokenMap - token-map for analyze
   */
  TokenMap m_tokenMap;
};

#endif // ERRORHANDLER_H
