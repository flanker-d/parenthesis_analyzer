#ifndef DATA_TYPES_H
#define DATA_TYPES_H

typedef enum ParenthesisType_e
{
  ParenthesisType_NoParenthsis = 0,

  ParenthesisType_OpenRound = -1,
  ParenthesisType_CloseRound = 1,

  ParenthesisType_OpenSquare = -2,
  ParenthesisType_CloseSquare = 2,

  ParenthesisType_OpenCurly = -3,
  ParenthesisType_CloseCurly = 3,

  ParenthesisType_OpenAngled = -4,
  ParenthesisType_CloseAngled = 4,

} ParenthesisType_e;

typedef enum states_e
{
  states_init = 0,
  states_round_open = '(',
  states_round_close = ')',
  states_square_open = '[',
  states_square_close = ']',
  states_figur_open = '{',
  states_figur_close = '}'

} states_e;


typedef struct Token_T
{
  ParenthesisType_e parenthesisType;
  int position;

  Token_T() : parenthesisType(ParenthesisType_e::ParenthesisType_NoParenthsis), position(0) {}

} Token_T;


#endif // DATA_TYPES_H
