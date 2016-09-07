#include "TokenMap.h"

TokenMap::TokenMap()
{
  m_token_map['\x01'] = TokenType_FinishToken; //0x01 == 1
  m_token_map['\xFF'] = TokenType_StartToken;  //0xFF == -1

  m_token_map['('] = TokenType_BracketOpenRound;
  m_token_map[')'] = TokenType_BracketCloseRound;

#ifdef PARENTHESIS_ONLY
  m_token_map['['] = TokenType_BracketOpenSquare;
  m_token_map[']'] = TokenType_BracketCloseSquare;

  m_token_map['{'] = TokenType_BracketOpenCurly;
  m_token_map['}'] = TokenType_BracketCloseCurly;

  m_token_map['<'] = TokenType_BracketOpenAngled;
  m_token_map['>'] = TokenType_BracketCloseAngled;
#endif
}

TokenType_e TokenMap::GetBracketType(char c)
{
  auto it = m_token_map.find(c);

  if(it != m_token_map.end())
    return it->second;
  else
    return TokenType_NoParenthsis;
}
