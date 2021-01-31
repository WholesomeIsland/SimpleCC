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
        if (line.find("declare ") != string::npos)
        {
            vector<string> splline = split(spltmp[it], string(" "));
            string nline = string(splline[1].append(string(" ").append(splline[2])).append("("));
            for (int  i = 3; i < splline.size(); i++)
            {
                nline.append(string(" ") + splline[i]);
            }
            spltmp[it] = nline;
            spltmp[it].append("){");
            nline = Process(nline);
            vector<string> splnline = split(nline, " ");
            for(int i = 0; i <= 8; i++)
        {
        	keyword var = keywords[i];
            if(splnline[2].find(var.cword) != string::npos){
                errors.push_back(sccError(string("Syntax Error: Keyword appears in name of a function on line ") + to_string(it),1));
            }
        }
        }
    }
}