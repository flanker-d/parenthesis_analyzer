#ifndef TOKENMAP_H
#define TOKENMAP_H

#include "DataTypes.h"
#include <map>

/**
  \brief The TokenMap class is used to
*/

/**
 * @brief The TokenMap class
 */
class TokenMap
{
public:
  /**
   * @brief TokenMap constructor. Fill std::map<char, TokenType_e> by initial values
   */
  TokenMap();

  /**
   * @brief Method produces 'char' conversion to token-type (TokenType_e) value
   * @param c - input character
   * @return converted TokenType_e value
   */
  TokenType_e GetParenthesisType(char c);

private:
  std::map<char, TokenType_e> m_token_map;
};

#endif // TOKENMAP_H
