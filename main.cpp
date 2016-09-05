#include <iostream>
#include <stack>

//std::string input_str = "(123[456{789}(123[456{789}])])";
std::string input_str = "(123[456{789}}])";

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

class analyzer
{
private:
  void analyze_next_symbol(std::string &input_string)
  {
    m_pos++;
    input_string = input_string.substr(1);
    if(input_string.size() > 0)
      analyze_it(input_string);
    else
      std::cout << "success" << std::endl;
  }

public:
  analyzer() : m_cur_state(states_e::states_init), m_pos(0)
  {
  }
  void analyze_it(std::string &input_string)
  {
    char cur_symbol = input_string.front();
    switch(cur_symbol)
    {
    case states_e::states_round_open:
    {
      state_t state;
      state.state = states_e::states_round_open;
      state.pos = m_pos;
      m_stack.push(state);
      break;
    }
    case states_e::states_round_close:
    {
      state_t last_state = m_stack.top();
      if(last_state.state == states_e::states_round_open)
        m_stack.pop();
      else
      {
        std::cout << "error: round_close [from pos " << last_state.pos << " to " << m_pos << "]" << std::endl;
      }
      break;
    }
    case states_e::states_square_open:
    {
      state_t state;
      state.state = states_e::states_square_open;
      state.pos = m_pos;
      m_stack.push(state);
      break;
    }
    case states_e::states_square_close:
    {
      state_t last_state = m_stack.top();
      if(last_state.state == states_e::states_square_open)
        m_stack.pop();
      else
        std::cout << "error: square_close [from pos " << last_state.pos << " to " << m_pos << "]" << std::endl;
      break;
    }
    case states_e::states_figur_open:
    {
      state_t state;
      state.state = states_e::states_figur_open;
      state.pos = m_pos;
      m_stack.push(state);
      break;
    }
    case states_e::states_figur_close:
    {
      state_t last_state = m_stack.top();
      if(last_state.state == states_e::states_figur_open)
        m_stack.pop();
      else
        std::cout << "error: figur_close [from pos " << last_state.pos << " to " << m_pos << "]" << std::endl;
      break;
    }
    default:
      break;
    }
    analyze_next_symbol(input_string);
  }

private:
  states_e m_cur_state;
  std::stack<state_t> m_stack;
  int m_pos;
};

int main(int argc, char **argv)
{
  analyzer anal;
  anal.analyze_it(input_str);

  return 0;
}
