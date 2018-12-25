#include "SymbolTable.h"

void SymbolTable::addVar(string name) {
    m_symbol_table.insert({name, 0});
}