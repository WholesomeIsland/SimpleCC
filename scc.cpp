// SimpleCToC.cpp : Defines the entry point for the application.
//

#include "SimpleCToC.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cout << "scc: Error, 2 arguments only." << std::endl;
		return 1;
	}
	ofstream outputfile(argv[2]);
	outputfile << Process(readFile(argv[1]));
	return 0;
}
