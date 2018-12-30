#ifndef PROJECT_PARSER_H
#define PROJECT_PARSER_H

#include <map>
#include <vector>
#include <string>
#include "Command.h"
#include <list>
#include "GlobalData.h"
#include "LoopCommand.h"
#include "IfCommand.h"

using namespace std;

/****************************************************************
* Class Name: Parser                                            *
* Constructor: Pointer to GlobalData                            *
* Class Functionality: This class receives a vector of the      *
*   entire script. It contains a map member of all the Command  *
*   classes that it calls upon when their keyword is read by    *
*   the parser. The parser then executes the Command object with*
*   the script and current index as the execution parameters.   *
****************************************************************/
class Parser {
    // members
    GlobalData *m_data;
    map<string, Command*> m_command_map;
public:
    explicit Parser(GlobalData *data); // constructor
    void parse(vector<string> script); // parse the entire script line by line
};


#endif //PROJECT_PARSER_H
