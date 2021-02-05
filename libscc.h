#include "SimpleCToC.h"
#include <string>
class sccError {
    public:
        sccError(string err, int errcode);
        string error;
        int errorcode;
};
sccError::sccError(string err, int errcode){
this->error = err;
this->errorcode = errcode;
}

vector<sccError> sccGetErrors(string filetxt){
    string tmp = filetxt;
    vector<string> spltmp = split(tmp, string("\n"));
    vector<sccError> errors = vector<sccError>();
    for (int it = 0; it != spltmp.size(); it++)
    {    
        string line = spltmp[it];
        if (line.find("declare") != string::npos)
        {
            errors.push_back(sccError(string("Warning: Make sure that no keywords are in the function name. on line: ") + to_string(it),1));
        }
    }
    return errors;
}