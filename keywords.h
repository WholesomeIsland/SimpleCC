typedef struct keyword {
    char* scword;
    char* cword;
}keyword;
keyword keywords[8];
void InitKeywords() {
    for (int i = 0; i < 8; i++)
    {
        keyword* k = (keyword*)malloc(sizeof(keyword));
        keywords[i] = *k;
    }
    keywords[0].cword = "if(";
    keywords[0].scword = "if ";
    keywords[1].cword = "){";
    keywords[1].scword = "then";
    keywords[2].cword = "}";
    keywords[2].scword = "end";
    keywords[3].cword = "int main(";
    keywords[3].scword = "main ";
    keywords[4].cword = "switch(";
    keywords[4].scword = "switch ";
    keywords[5].cword = "} else {";
    keywords[5].scword = "else ";
    keywords[6].cword = "unsigned int";
    keywords[6].scword = "uint ";
    keywords[7].cword = " ";
    keywords[7].scword = "Call ";
}