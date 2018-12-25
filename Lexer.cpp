#include "Lexer.h"


vector<string> Lexer::splitter(string text, const char c) {
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

    strings.push_back(current);
    return strings;
}

vector<string> Lexer::lexer(string line) {
    string processedLine = processLine(line);
    return splitter(processedLine, ' ');
}

bool Lexer::isIn(char c, string op) {
    for (int i = 0; i < op.length(); i++) {
        if (c == op[i]) {
            return true;
        }
    }
    return false;
}

string Lexer::processLine(const string line) {
    string newString;
    string op = "*+=-/<>()";
    bool isAddress = 0;
    int i = 0;
    while (i < line.length()) {
        if (!isAddress && line[i] == '"') {
            isAddress = 1;
            i++;
        }
        if (isAddress && line[i]=='"'){
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