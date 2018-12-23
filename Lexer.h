#ifndef PROJECT_LEXER_H
#define PROJECT_LEXER_H

#include <string>

#include <vector>

using namespace std;

class Lexer {
private:
    vector<string> splitter(string text,const char c);
    vector<string> lexer(string line);
};

#endif //PROJECT_LEXER_H
