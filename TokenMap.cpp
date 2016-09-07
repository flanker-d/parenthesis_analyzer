#include "TokenMap.h"

TokenMap::TokenMap()
{
  m_map['\x01'] = TokenType_FinishToken; //0x01 == 1
  m_map['\xFF'] = TokenType_StartToken;  //0xFF == -1

  m_map['('] = TokenType_ParenOpenRound;
  m_map[')'] = TokenType_ParenCloseRound;

  m_map['['] = TokenType_ParenOpenSquare;
  m_map[']'] = TokenType_ParenCloseSquare;

  m_map['{'] = TokenType_ParenOpenCurly;
  m_map['}'] = TokenType_ParenCloseCurly;

  m_map['<'] = TokenType_ParenOpenAngled;
  m_map['>'] = TokenType_ParenCloseAngled;
}

TokenType_e TokenMap::GetParenthesisType(char c)
{
  auto it = m_map.find(c);

  if(it != m_map.end())
    return it->second;
  else
    return TokenType_NoParenthsis;
}
