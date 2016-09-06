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

bool Analyzer::AnalyzeOpenParenthesis(ParenthesisType_e a_type)
{
  Token_T token;
  token.parenthesisType = a_type;
  token.position = m_pos;
  m_stack.push(token);
  return true;
}

bool Analyzer::AnalyzeCloseParenthesis(ParenthesisType_e a_type)
{
  Token_T last_stack_token = m_stack.top();
  ParenthesisType_e mirrorType = (ParenthesisType_e) -a_type;
  if(last_stack_token.parenthesisType == mirrorType)
  {
    m_stack.pop();
    return true;
  }
  else
  {
    std::cout << "error: round_close [from pos " << last_stack_token.position << " to " << m_pos << "]" << std::endl;
    return false;
  }
}

Analyzer::Analyzer() : m_curState(states_e::states_init), m_pos(0)
{
}

void Analyzer::AnalyzeIt(std::string &input_string)
{
  bool result = false;
  char cur_symbol = input_string.front();

  ParenthesisType_e parenthesis_type = m_token_map.GetParenthesisType(cur_symbol);

  switch(parenthesis_type)
  {
  case ParenthesisType_OpenAngled:
  case ParenthesisType_OpenCurly:
  case ParenthesisType_OpenRound:
  case ParenthesisType_OpenSquare:
    result = AnalyzeOpenParenthesis((ParenthesisType_e) parenthesis_type);
    break;
  case ParenthesisType_CloseAngled:
  case ParenthesisType_CloseCurly:
  case ParenthesisType_CloseRound:
  case ParenthesisType_CloseSquare:
    result = AnalyzeCloseParenthesis((ParenthesisType_e) parenthesis_type);
    break;
  default:
    result = true;
    break;
  }

  if(result)
    AnalyzeNextSymbol(input_string);
  else
    return;
}
