#include "TokenMap.h"

TokenMap::TokenMap()
{
  m_tokenMap['\x01'] = TokenType_FinishToken; //0x01 == 1
  m_tokenMap['\xFF'] = TokenType_StartToken;  //0xFF == -1

  m_tokenMap['('] = TokenType_BracketOpenRound;
  m_tokenMap[')'] = TokenType_BracketCloseRound;

#ifdef ALL_BRACKETS
  m_token_map['['] = TokenType_BracketOpenSquare;
  m_token_map[']'] = TokenType_BracketCloseSquare;

  m_token_map['{'] = TokenType_BracketOpenCurly;
  m_token_map['}'] = TokenType_BracketCloseCurly;

  m_token_map['<'] = TokenType_BracketOpenAngled;
  m_token_map['>'] = TokenType_BracketCloseAngled;
#endif
}

TokenType_e TokenMap::CharToTokenType(char c)
{
  auto it = m_tokenMap.find(c);

  if(it != m_tokenMap.end())
    return it->second;
  else
    return TokenType_NoParenthsis;
}

char TokenMap::TokenTypeToChar(TokenType_e a_tokenType)
{
  for(auto it = m_tokenMap.begin(); it != m_tokenMap.end(); ++it)
  {
    if(it->second == a_tokenType)
      return it->first;
  }
  return '\0';
}
