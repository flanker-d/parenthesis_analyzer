#include "Analyzer.h"

int main(int argc, char **argv)
{
  Analyzer analyzer;

  for (std::string string_to_analyze; std::getline(std::cin, string_to_analyze);)
  {
    //std::cout << string_to_analyze << std::endl;
    bool res = analyzer.AnalyzeString(string_to_analyze);
    if(!res)
      break;
  }

  return 0;
}
