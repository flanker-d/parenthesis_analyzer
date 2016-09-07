#include "Analyzer.h"

int main(int argc, char **argv)
{
  Analyzer analyzer;

  for (std::string string_to_analyze; std::getline(std::cin, string_to_analyze);)
  {
    std::cout << string_to_analyze << std::endl;
    analyzer.AnalyzeString(string_to_analyze);
  }

  return 0;
}
