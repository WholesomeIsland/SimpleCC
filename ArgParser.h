#pragma once
#include <string>
#include <cstring>
#include <vector>
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
    for(int i = 0; i < argc - 1; i++){
        if(strcmp("-o", argv[i])){
            retval.oFile = argv[(i + 1)];
        } else
        if(strcmp("--transpile", argv[i]) || strcmp("-t", argv[i])){
            retval.ctype = TRANSPILE;
        } else
        if(strcmp("--compile", argv[i]) || strcmp("-c", argv[i])){
            retval.ctype = COMPILE;
        } else
        if(strcmp("--run", argv[i]) || strcmp("-r", argv[i])){
            retval.ctype = RUN;
        } else {
            retval.iFiles.push_back(std::string(argv[i]));
        }
    }
    return retval;
}
