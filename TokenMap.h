#ifndef TOKENMAP_H
#define TOKENMAP_H

#include "data_types.h"
#include <map>

class TokenMap
{
public:
  TokenMap()
  {
    m_map['('] = ParenthesisType_OpenRound;
    m_map[')'] = ParenthesisType_CloseRound;

    m_map['['] = ParenthesisType_OpenSquare;
    m_map[']'] = ParenthesisType_CloseSquare;

    m_map['{'] = ParenthesisType_OpenCurly;
    m_map['}'] = ParenthesisType_CloseCurly;

    m_map['<'] = ParenthesisType_OpenAngled;
    m_map['>'] = ParenthesisType_CloseAngled;
  }

  ParenthesisType_e GetParenthesisType(char c)
  {
    auto it = m_map.find(c);

    if(it != m_map.end())
      return it->second;
    else
      return ParenthesisType_NoParenthsis;
  }

private:
  std::map<char, ParenthesisType_e> m_map;
};

#endif // TOKENMAP_H
