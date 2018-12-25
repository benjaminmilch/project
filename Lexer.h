#ifndef PROJECT_LEXER_H
#define PROJECT_LEXER_H

#include <string>

#include <vector>

using namespace std;

class Lexer {
public:
    vector<string> splitter(string text,const char c);
    vector<string> lexer(string line);
    string processLine(const string line);
    bool isIn(char c, string op);
};

#endif //PROJECT_LEXER_H
