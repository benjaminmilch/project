#ifndef PROJECT_VARTABLE_H
#define PROJECT_VARTABLE_H

#include <vector>
#include <string>
#include <map>

using namespace std;

class SymbolTable {
    map<string, double> m_symbol_table;
public:
    void addVar(string name);
};


#endif //PROJECT_VARTABLE_H