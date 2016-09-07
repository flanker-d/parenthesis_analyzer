#include "Analyzer.h"

bool Analyzer::AnalyzeNextSymbol(std::string &input_string)
{
  m_pos++;
  input_string = input_string.substr(1);
  if(input_string.size() > 0)
  {
    if(!AnalyzeIt(input_string))
      return false;
  }
  else
    std::cout << "success" << std::endl;
  return true;
}

void Analyzer::ClearTokenStack()
{
  while(m_stack.size() > 0)
    m_stack.pop();
}

void Analyzer::InitTokenStack()
{
  Token_T token;
  token.parenthesisType = TokenType_StartToken;
  token.position = m_pos;
  m_stack.push(token);
}

void Analyzer::InitAnalyzer()
{
  m_pos = 0;
  ClearTokenStack();
  InitTokenStack();
}

bool Analyzer::AnalyzeOpenParenthesis(TokenType_e a_type)
{
  Token_T token;
  token.parenthesisType = a_type;
  token.position = m_pos;
  m_stack.push(token);
  return true;
}

bool Analyzer::AnalyzeCloseParenthesis(TokenType_e a_type)
{
  Token_T last_stack_token = m_stack.top();
  TokenType_e mirrorType = (TokenType_e) -a_type;
  if(last_stack_token.parenthesisType == mirrorType)
  {
    m_stack.pop();
    return true;
  }
  else
  {
    std::cout << "error: at line: " << m_str_count << " pos: " << m_pos << "" << std::endl;
    return false;
  }
}

Analyzer::Analyzer() : m_pos(0), m_str_count(0)
{
}

bool Analyzer::AnalyzeIt(std::string &input_string)
{
  bool result = false;
  char cur_symbol = input_string.front();

  TokenType_e parenthesis_type = m_token_map.GetParenthesisType(cur_symbol);

  switch(parenthesis_type)
  {
  case TokenType_ParenOpenAngled:
  case TokenType_ParenOpenCurly:
  case TokenType_ParenOpenRound:
  case TokenType_ParenOpenSquare:
    result = AnalyzeOpenParenthesis((TokenType_e) parenthesis_type);
    break;

  case TokenType_ParenCloseAngled:
  case TokenType_ParenCloseCurly:
  case TokenType_ParenCloseRound:
  case TokenType_ParenCloseSquare:
  case TokenType_FinishToken:
    result = AnalyzeCloseParenthesis((TokenType_e) parenthesis_type);
    break;

  default:
    result = true;
    break;
  }

  if(result)
    result = AnalyzeNextSymbol(input_string);

  return result;
}

bool Analyzer::AnalyzeString(std::string &input_string)
{
  InitAnalyzer();
  input_string.push_back(TokenType_FinishToken);
  bool res = AnalyzeIt(input_string);
  m_str_count++;
  return res;
}
