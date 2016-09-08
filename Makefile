all:
	g++ -std=c++11 Analyzer.cpp ErrorHandler.cpp main.cpp TokenMap.cpp -o analyzer

clean:
	rm -f analyzer

