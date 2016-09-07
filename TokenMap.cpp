#include "TokenMap.h"

TokenMap::TokenMap()
{
  m_token_map['\x01'] = TokenType_FinishToken; //0x01 == 1
  m_token_map['\xFF'] = TokenType_StartToken;  //0xFF == -1

  m_token_map['('] = TokenType_ParenOpenRound;
  m_token_map[')'] = TokenType_ParenCloseRound;

  m_token_map['['] = TokenType_ParenOpenSquare;
  m_token_map[']'] = TokenType_ParenCloseSquare;

  m_token_map['{'] = TokenType_ParenOpenCurly;
  m_token_map['}'] = TokenType_ParenCloseCurly;

  m_token_map['<'] = TokenType_ParenOpenAngled;
  m_token_map['>'] = TokenType_ParenCloseAngled;
}

TokenType_e TokenMap::GetParenthesisType(char c)
{
  auto it = m_token_map.find(c);

  if(it != m_token_map.end())
    return it->second;
  else
    return TokenType_NoParenthsis;
}
