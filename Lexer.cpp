#include "Lexer.h"

vector<string> Lexer::splitter(string text,const char c) {
    vector<string> strings;
    string current;
    for (char i : text) {
        if (i != c) {
            current += i;
        } else {
            strings.push_back(current);
            current = "";
        }
    }
    return strings;
}
vector<string> Lexer::lexer(string line) {
    return splitter(line, ' ');
}