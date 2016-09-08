#ifndef TOKENMAP_H
#define TOKENMAP_H

#include "DataTypes.h"
#include <map>

/**
 * @brief class for storage informations about tokens. Contains methods for converting types
 */
class TokenMap
{
public:
  /**
   * @brief TokenMap constructor. Fill std::map<char, TokenType_e> by initial values
   */
  TokenMap();

  /**
   * @brief CharToTokenType - Method converts input 'char' to output 'TokenType_e'
   * @param c - input character
   * @return 'TokenType_e' value
   */
  TokenType_e CharToTokenType(char c);

  /**
   * @brief TokenTypeToChar - Method converts input 'TokenType_e' to output 'char'
   * @param a_tokenType - input 'TokenType_e'
   * @return 'char' value
   */
  char TokenTypeToChar(TokenType_e a_tokenType);

private:
  /**
   * @brief m_tokenMap - container for storing informations about tokens
   */
  std::map<char, TokenType_e> m_tokenMap;
};

#endif // TOKENMAP_H
