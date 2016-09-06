#include "Analyzer.h"

//std::string input_str = "(123[456{789}(123[456{789}])])";
std::string input_str = "(123[456{789}])";
//std::string input_str = "(123[456{789}}])";


int main(int argc, char **argv)
{
  Analyzer anal;
  anal.AnalyzeIt(input_str);

  return 0;
}
