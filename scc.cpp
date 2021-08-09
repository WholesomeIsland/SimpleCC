// SimpleCToC.cpp : Defines the entry point for the application.
//

#include "SimpleCToC.h"
#include "libscc.h"
using namespace std;
 string helpstr = "Welcome to scc, the simpleC compiler.\nflags:\n-h,--help display this message.\n-t,--transpile: default mode, transpiles SimpleC to C\n-c,--compile: transpile, then compile SimpleC with clang.\n-r,--run: compile with clang, then run the output.\nusage:\nscc [inputfile] [-t, -c, -r] (extra flags)";
int main(int argc, char** argv)
{
	/*if (strcmp(argv[1],"-h") || strcmp(argv[1], "--help"))
	{
		cout << helpstr << endl;
	}*/
	run(argv, argc);
		vector<sccError> errors = sccGetErrors(readFile(argv[1]));
		for(int i = 0; i < errors.size(); i++){
      std::cout << errors[i].error << std::endl;
    }
	return 0;
}
