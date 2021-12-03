#pragma once
#include <string>
#include <cstring>
#include <vector>
#define CXXOPTS_NO_REGEX
#include "cxxopts.hpp"
enum CompileType {
    TRANSPILE,
    COMPILE,
    RUN,
};

struct Arguments {
    CompileType ctype;
    std::string oFile;
    std::vector<std::string> iFiles;
    bool isHelp;
};

Arguments getArgs(char** argv, int argc){
    Arguments retval = Arguments();
    int option = 0;
    retval.iFiles = std::vector<std::string>();
    cxxopts::Options opts("SimpleCC", "Compiler for SimpleC");
    opts.add_options()("c,compiler", "compile only", cxxopts::value<int>())
    ("r,run", "compile and run", cxxopts::value<int>())
    ("t,transpile", "transpile into C only", cxxopts::value<int>())
    ("o,output", "File to output to", cxxopts::value<std::string>())
    ("i,input", "Input files", cxxopts::value<std::vector<std::string>>())
     ("h,help", "help", cxxopts::value<bool>());
    auto result = opts.parse(argc, argv);
    if(result["t"].count() == 1){
        retval.ctype = TRANSPILE;
    }
    if(result["c"].count() == 1){
        retval.ctype = COMPILE;
    }
    if (result["r"].count() == 1)
    {
        retval.ctype = RUN;
    }
    retval.isHelp = result["h"].as<bool>();
    if (retval.isHelp)
    {
        return retval;
    }
    retval.oFile = result["o"].as<std::string>();
    retval.iFiles = result["i"].as<std::vector<std::string>>();
    return retval;
}
