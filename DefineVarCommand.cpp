#include "DefineVarCommand.h"

void DefineVarCommand::execute(vector<string> line)
{
     m_var_map.insert({line[1], line[4]});
     m_symbolTable.insert({line[1], 0});
}
