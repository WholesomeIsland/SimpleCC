#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "keywords.h"
using namespace std;
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if (from.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}
string readFile(const string& fileName)
{
    ifstream ifs(fileName.c_str(), ios::in | ios::binary | ios::ate);

    ifstream::pos_type fileSize = ifs.tellg();
    if (fileSize < 0)
        return std::string();

        ifs.seekg(0, ios::beg);

    vector<char> bytes(fileSize);
    ifs.read(&bytes[0], fileSize);

    return string(&bytes[0], fileSize);
}

vector<string> split(const string& str, const string& delim)
{
vector<string> tokens;
size_t prev = 0, pos = 0;
do
{
    pos = str.find(delim, prev);
    if (pos == string::npos) pos = str.length();
    string token = str.substr(prev, pos - prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
} while (pos < str.length() && prev < str.length());
return tokens;
}
std::string Process(std::string strtp) {
    InitKeywords();
    string tmp = strtp;
    vector<string> spltmp = split(tmp, string("\n"));
    for (int it = 0; it != spltmp.size(); it++)
    {
        string line = spltmp[it];
        if (line.find("Call ") != string::npos)
        {
            spltmp[it].append(";");
        }
        if (line.find(" = ") != string::npos)
        {
            spltmp[it].append(";");
        }        
        if (line.find("declare ") != string::npos)
        {
            spltmp[it].append("(){");
        }
        for(int i = 0; i <= 8; i++)
        {
        	keyword var = keywords[i];
            replaceAll(spltmp[it], var.scword, var.cword);
        }
    }
    string rtnval = string();
    for (int it = 0; it != spltmp.size(); it++)
    {
        rtnval += spltmp[it];
    }
    return rtnval;
}
