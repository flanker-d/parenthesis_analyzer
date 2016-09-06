#include "Analyzer.h"

void Analyzer::AnalyzeNextSymbol(std::string &input_string)
{
  m_pos++;
  input_string = input_string.substr(1);
  if(input_string.size() > 0)
    AnalyzeIt(input_string);
  else
    std::cout << "success" << std::endl;
}

void Analyzer::AnalyzeOpenParenthesis(states_e a_state)
{
  state_t state;
  state.state = a_state;
  state.pos = m_pos;
  m_stack.push(state);
}

void Analyzer::AnalyzeCloseParenthesis(states_e a_state)
{
  state_t last_state = m_stack.top();
  if(last_state.state == a_state)
    m_stack.pop();
  else
  {
    std::cout << "error: round_close [from pos " << last_state.pos << " to " << m_pos << "]" << std::endl;
  }
}

Analyzer::Analyzer() : m_curState(states_e::states_init), m_pos(0)
{
}

void Analyzer::AnalyzeIt(std::string &input_string)
{
  char cur_symbol = input_string.front();
  switch(cur_symbol)
  {
  case states_e::states_round_open:
    AnalyzeOpenParenthesis(states_e::states_round_open);
    break;
  case states_e::states_round_close:
    AnalyzeCloseParenthesis(states_e::states_round_open);
    break;
  case states_e::states_square_open:
    AnalyzeOpenParenthesis(states_e::states_square_open);
    break;
  case states_e::states_square_close:
    AnalyzeCloseParenthesis(states_e::states_square_open);
    break;
  case states_e::states_figur_open:
    AnalyzeOpenParenthesis(states_e::states_figur_open);
    break;
  case states_e::states_figur_close:
    AnalyzeCloseParenthesis(states_e::states_figur_open);
    break;
  default:
    break;
  }
  AnalyzeNextSymbol(input_string);
}
