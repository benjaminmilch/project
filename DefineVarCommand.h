#ifndef PROJECT_DEFINEVARCOMMAND_H
#define PROJECT_DEFINEVARCOMMAND_H

#include "Command.h"
#include <map>

using namespace std;

class DefineVarCommand : public Command {
    map<string, string> m_var_map;
    map<string, double> m_symbolTable;
public:
    void execute(vector<string> line);
};


#endif //PROJECT_DEFINEVARCOMMAND_H
