#include "Analyzer.h"

bool Analyzer::AnalyzeNextSymbol(std::string &a_inputString)
{
  m_pos++;
  a_inputString = a_inputString.substr(1);
  if(a_inputString.size() > 0)
  {
    // error detected
    if(!AnalyzeCurChar(a_inputString))
    {
      return false;
    }
  }
  else
  {
    // success
    m_errorHandler.ProcessSuccess(m_strCount);
  }

  return true;
}

void Analyzer::InitTokenStack()
{
  Token_T token;
  token.tokenType = TokenType_StartToken;
  token.position = m_pos;
  m_tokensStack.push(token);
}

void Analyzer::InitAnalyzer()
{
  m_pos = 0;
  InitTokenStack();
}

bool Analyzer::PushOpenBracketToStack(TokenType_e a_tokenType)
{
  Token_T token;
  token.tokenType = a_tokenType;
  token.position = m_pos;
  m_tokensStack.push(token);
  return true;
}

bool Analyzer::AnalyzeCloseBracket(TokenType_e a_tokenType)
{
  Token_T lastStackToken = m_tokensStack.top();
  TokenType_e mirrorType = (TokenType_e) -a_tokenType;
  if(lastStackToken.tokenType == mirrorType)
  {
    m_tokensStack.pop();
    return true;
  }
  else
  {
    m_errorHandler.ProcessError(lastStackToken, a_tokenType, m_strCount, m_pos);
    return false;
  }
}

Analyzer::Analyzer() : m_pos(0), m_strCount(0)
{
}

bool Analyzer::AnalyzeCurChar(std::string &a_inputString)
{
  bool result = false;
  char curSymbol = a_inputString.front();

  TokenType_e tokenType = m_tokenMap.CharToTokenType(curSymbol);

  switch(tokenType)
  {
#ifdef ALL_BRACKETS
  case TokenType_BracketOpenAngled:
  case TokenType_BracketOpenCurly:
  case TokenType_BracketOpenSquare:
#endif
  case TokenType_BracketOpenRound:
    result = PushOpenBracketToStack((TokenType_e) tokenType);
    break;

#ifdef ALL_BRACKETS
  case TokenType_BracketCloseAngled:
  case TokenType_BracketCloseCurly:
  case TokenType_BracketCloseSquare:
#endif
  case TokenType_BracketCloseRound:
  case TokenType_FinishToken:
    result = AnalyzeCloseBracket((TokenType_e) tokenType);
    break;

  default:
    result = true;
    break;
  }

  if(result)
  {
    result = AnalyzeNextSymbol(a_inputString);
  }

  return result;
}

void Analyzer::AnalyzeString(std::string &a_inputString)
{
  InitAnalyzer();
  a_inputString.push_back(TokenType_FinishToken);
  AnalyzeCurChar(a_inputString);
  m_strCount++;
}
