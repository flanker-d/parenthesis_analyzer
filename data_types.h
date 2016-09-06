#ifndef DATA_TYPES_H
#define DATA_TYPES_H

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

typedef struct state_t
{
  states_e state;
  int pos;

  state_t() : state(states_e::states_init), pos(0) {}

} state_t;


#endif // DATA_TYPES_H
