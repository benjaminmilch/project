//
// Created by ben on 12/25/18.
//

#ifndef PROJECT_ADDRESSTABLE_H
#define PROJECT_ADDRESSTABLE_H

#include <map>
#include <string>

using namespace std;

class AddressTable {
    map<string, string> m_address_table;
public:
    AddressTable();
    void addVarName(string name);
};


#endif //PROJECT_ADDRESSTABLE_H
