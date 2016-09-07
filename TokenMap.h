#ifndef TOKENMAP_H
#define TOKENMAP_H

#include "data_types.h"
#include <map>

class TokenMap
{
public:
  TokenMap();
  TokenType_e GetParenthesisType(char c);

private:
  std::map<char, TokenType_e> m_map;
};

#endif // TOKENMAP_H
