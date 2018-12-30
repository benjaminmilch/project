#ifndef PROJECT_LEXER_H
#define PROJECT_LEXER_H

#include <string>

#include <vector>
#include <fstream>
using namespace std;

/****************************************************************
* Class Name: Lexer                                             *
* Constructor: Default constructor                              *
* Class Functionality: Receives the file name of the text to be *
*   read from and split by word into a vector of strings. Lexer *
*   also handles the situation of expressions having spaces or  *
*   not by adding spaces between the operators and their        *
*   adjacent expression (number/variable name) if there isn't   *
*   already one present. Returns a vector of strings of the     *
*   entire script.                                              *
****************************************************************/
class Lexer {
public:
    vector<string> lexer(string fileName); // main method that returns the final vector of the script
    vector<string> splitter(string text, const char c); // splits the line by spaces
    vector<string> lex(string line); // uses splitter() and processLine() to "lex" the line of text
    string processLine(const string line); // process the line based on space/operators
    bool isIn(char c, string op); // searches for exists of a specific char in the string
};

#endif //PROJECT_LEXER_H
