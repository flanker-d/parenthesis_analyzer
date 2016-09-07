#ifndef DATA_TYPES_H
#define DATA_TYPES_H

typedef enum TokenType_e
{
  TokenType_NoParenthsis = 0,

  TokenType_StartToken = -1, //0xFF
  TokenType_FinishToken = 1, //0x01

  TokenType_ParenOpenRound = -10,
  TokenType_ParenCloseRound = 10,

  TokenType_ParenOpenSquare = -20,
  TokenType_ParenCloseSquare = 20,

  TokenType_ParenOpenCurly = -30,
  TokenType_ParenCloseCurly = 30,

  TokenType_ParenOpenAngled = -40,
  TokenType_ParenCloseAngled = 40,

} TokenType_e;

typedef struct Token_T
{
  TokenType_e parenthesisType;
  int position;

  Token_T() : parenthesisType(TokenType_e::TokenType_NoParenthsis), position(0) {}

} Token_T;


#endif // DATA_TYPES_H
