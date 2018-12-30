#include <iostream>
#include "Lexer.h"


#include <unistd.h>

#include "Parser.h"


int main(int argc, char *argv[]) {

    GlobalData globalData;
    globalData.setHalt(true);

    Lexer l;
    vector<string> syntax = l.lexer(argv[1]);

    Parser p = Parser(&globalData);
    p.parse(syntax);

    return 0;
}