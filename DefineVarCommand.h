#ifndef PROJECT_DEFINEVARCOMMAND_H
#define PROJECT_DEFINEVARCOMMAND_H

#include "Command.h"
#include <map>
#include "SymbolTable.h"

using namespace std;

class DefineVarCommand : public Command{
    SymbolTable* m_symbol_table;
    vector<string> line;
public:
    DefineVarCommand(SymbolTable* table);
    void execute(vector<string> line);
};


#endif //PROJECT_DEFINEVARCOMMAND_H