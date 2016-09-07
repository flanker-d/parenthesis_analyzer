#ifndef DATA_TYPES_H
#define DATA_TYPES_H

/** @file DataTypes.h
 *  This is a data type header file, included by other program headers.
 */

//#define PARENTHESIS_ONLY

typedef enum TokenType_e
{
  TokenType_NoParenthsis = 0,

  TokenType_StartToken = -1, //0xFF
  TokenType_FinishToken = 1, //0x01

  TokenType_BracketOpenRound = -10,
  TokenType_BracketCloseRound = 10,

#ifdef PARENTHESIS_ONLY
  TokenType_BracketOpenSquare = -20,
  TokenType_BracketCloseSquare = 20,

  TokenType_BracketOpenCurly = -30,
  TokenType_BracketCloseCurly = 30,

  TokenType_BracketOpenAngled = -40,
  TokenType_BracketCloseAngled = 40,
#endif

} TokenType_e;



typedef struct Token_T
{
  TokenType_e tokenType;
  int position;

  Token_T() : tokenType(TokenType_e::TokenType_NoParenthsis), position(0) {}

} Token_T;


#endif // DATA_TYPES_H
