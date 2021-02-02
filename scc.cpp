﻿// SimpleCToC.cpp : Defines the entry point for the application.
//

#include "SimpleCToC.h"
#include "libscc.h"
using namespace std;
 string helpstr = R"(Welcome to scc, the simpleC transpiler.
flags:
	-h,--help display this message.
usage:
	scc [inputfile] [outputfile]
 )";
int main(int argc, char** argv)
{
	if (argv[1] == "-h" || argv[1] == "--help")
	{
		cout << helpstr << endl;
	}
	if (argc != 3)
	{
		std::cout << "scc: Error, Invalid number of arguments." << std::endl;
		return 1;
	}
	ofstream outputfile(argv[2]);
	outputfile << Process(readFile(argv[1]));
		vector<sccError> errors = sccGetErrors(readFile(argv[1]));
		vector<string> splline = split(readFile(argv[1]), string("\n"));
		for(int i = 0; i < errors.size(); i++){
      std::cout << errors[i].error << std::endl;
    }
	return 0;
}