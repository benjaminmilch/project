#include "DefineVarCommand.h"

DefineVarCommand::DefineVarCommand(SymbolTable* table)
{
   m_symbol_table = table;
}
void DefineVarCommand::execute(vector<string> line) {
    m_symbol_table->addVar(line[1]);
}