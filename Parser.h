#ifndef PROJECT_PARSER_H
#define PROJECT_PARSER_H

#include <map>
#include <vector>
#include <string>
#include "Command.h"

using namespace std;

class Parser {
map<string, Command*> m_command_map;
public:
    Parser();
    void parse(vector<string> line);
};


#endif //PROJECT_PARSER_H
