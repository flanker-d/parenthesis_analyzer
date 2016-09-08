#include "ErrorHandler.h"

void ErrorHandler::ProcessError(Token_T &a_lastStackToken, TokenType_e a_curTokenType, int a_curLineNumber, int a_curPos)
{
  TokenType_e lastToken = a_lastStackToken.tokenType;
  switch (lastToken)
  {
#ifdef ALL_BRACKETS
  case TokenType_BracketOpenAngled:
  case TokenType_BracketOpenCurly:
  case TokenType_BracketOpenSquare:
#endif
  case TokenType_BracketOpenRound:
    std::cout << "line " << a_curLineNumber << ": fail at position: " << a_curPos
              << ", expected \'" << m_tokenMap.TokenTypeToChar((TokenType_e)-lastToken)
              << "\' after \'" << m_tokenMap.TokenTypeToChar(lastToken) << "\'" << std::endl;
    break;

  case TokenType_StartToken:
    std::cout << "line " << a_curLineNumber << ": fail at position: " << a_curPos
              << ", expected \'" << m_tokenMap.TokenTypeToChar((TokenType_e)-a_curTokenType)
              << "\' before \'" << m_tokenMap.TokenTypeToChar(a_curTokenType) << "\'" << std::endl;
    break;
  default:
    break;
  }
}

void ErrorHandler::ProcessSuccess(int a_curLineNumber)
{
  std::cout << "line " << a_curLineNumber << ": success" << std::endl;
}
