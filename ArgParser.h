#pragma once
#include <string>
#include <cstring>
#include <vector>
#include <getopt.h>
enum CompileType {
    TRANSPILE,
    COMPILE,
    RUN,
};

struct Arguments {
    CompileType ctype;
    std::string oFile;
    std::vector<std::string> iFiles;
};

Arguments getArgs(char** argv, int argc){
    Arguments retval = Arguments();
    int option = 0;
    retval.iFiles = std::vector<std::string>();
    while((option = getopt(argc, argv, "ctro:")) != -1){
        switch(option){
            case 'c':
                retval.ctype = COMPILE;
                break;
            case 't':
                retval.ctype = TRANSPILE;
                break;
            case 'r':
                retval.ctype = RUN;
                break;
            case 'o':
                retval.oFile = optarg;
            default:
                  for (int i = optind; i < argc; i++)
                    retval.iFiles.push_back(std::string(argv[i]));
                break;
        }
    }
    return retval;
}
