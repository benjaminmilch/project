//
// Created by ben on 12/25/18.
//

#include "PrintCommand.h"
#include <iostream>

PrintCommand::PrintCommand(GlobalData *data)
{
    m_data = data;
}
int PrintCommand::execute(vector<string> script, unsigned long index)
{
    int counter = 1;
    index++;
    string print;
    if (m_data->isExists(script[index])) {
        cout << m_data->getSymbolTable().at(script[index]) << endl;
        counter = 3;
    } else {
        while (script[index] != "\n") {
            print.append(script[index]);
            print.append(" ");
            index++;
            ++counter;
        }
        cout << print << endl;
        counter++;
    }
    return counter;
}
