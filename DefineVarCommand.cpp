#include "DefineVarCommand.h"

void DefineVarCommand::execute(vector<string> line)
{
     m_symbolTable.insert({line[0], 0});
}
