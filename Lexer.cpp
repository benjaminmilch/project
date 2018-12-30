#include <iostream>
#include "Lexer.h"
#include "fstream"


vector<string> Lexer::lexer(string fileName)
{
    ifstream file;
    string line;
    vector<string> syntax;
    vector<string> breakLine;
    file.open(fileName);

    if (file.fail()) {
        cerr << "ERROR opening file" << endl;
        exit(1);
    }
    while (getline(file, line)) {
        breakLine = lex(line);
        syntax.insert(syntax.end(), breakLine.begin(), breakLine.end());
        syntax.emplace_back("\n");
    }

    file.close();
    return syntax;
}

vector<string> Lexer::splitter(string text, const char c)
{
    vector<string> strings;
    string current;
    for (char& i : text) {
        if (i != c) {
            current += i;
        } else {
            if (current != "") {
                strings.push_back(current);
            }
            current = "";
        }
    }
    if (current != "") {
        strings.push_back(current);
    }
    return strings;
}

vector<string> Lexer::lex(string line)
{
    string processedLine = processLine(line);
    return splitter(processedLine, ' ');
}


bool Lexer::isIn(char c, string op)
{
    for (char& i : op) {
        if (c == i) {
            return true;
        }
    }
    return false;
}

string Lexer::processLine(const string line) {
    string newString;
    string op = "*+=-/<>()";
    bool isAddress = false;
    unsigned int i = 0;
    while (i < line.length()) {
        if (!isAddress && line[i] == '"') {
            isAddress = true;
            i++;
        }
        if (isAddress && line[i] == '"') {
            break;
        }
        if (!isAddress) {
            if (isIn(line[i], op)) {
                if (newString[newString.length() - 1] != ' ') {
                    newString += ' ';
                }
                newString += line[i];
                if (line[i + 1] == '=') {
                    i++;
                    newString += line[i];
                }
                if (line[i + 1] != ' ') {
                    newString += ' ';
                }
                i++;
                continue;
            }
        }
        newString += line[i];
        i++;
    }
    return newString;
}