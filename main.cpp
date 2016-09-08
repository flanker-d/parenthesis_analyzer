#include "Analyzer.h"

int main(int argc, char **argv)
{
  Analyzer analyzer;

  int exit_code = 0;
  while(true)
  {
    std::string string_to_analyze;
    std::getline(std::cin, string_to_analyze);

    if(std::feof(stdin))
    {
      std::cout << "EOF" << std::endl;
      exit_code = 0;
      break;
    }
    if(std::ferror(stdin))
    {
      std::cout << "read error" << std::endl;
      exit_code = 1;
      break;
    }
    //std::cout << string_to_analyze << std::endl;
    analyzer.AnalyzeString(string_to_analyze);
  }

  return exit_code;
}
