#ifndef PROJECT_PARSER_H
#define PROJECT_PARSER_H

#include <map>
#include <vector>
#include <string>
#include "Command.h"
#include "SymbolTable.h"

using namespace std;

class Parser {
map<string, Command*> m_command_map;
bool m_loop;
SymbolTable *m_symbol_table;
public:
    Parser();
    void parse(vector<string> line);
};


#endif //PROJECT_PARSER_H
