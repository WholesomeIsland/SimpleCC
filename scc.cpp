// SimpleCToC.cpp : Defines the entry point for the application.
//

#include "SimpleCToC.h"
#include "libscc.h"
using namespace std;
int main(int argc, char** argv)
{
	run(argv, argc);
		vector<sccError> errors = sccGetErrors(readFile(argv[1]));
    for(int i = 0; i < errors.size(); i++){
      std::cout << errors[i].error << std::endl;
    }
	return 0;
}
