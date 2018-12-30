//
// Created by ben on 12/25/18.
//

#include "BindCommand.h"

BindCommand::BindCommand(GlobalData *data)
{
    m_data = data;
}
int BindCommand::execute(vector<string> script, unsigned long index)
{
    m_data->addToAddressTable(script[index], script[index + 3]); // variable at "index" and address at "index + 3"
    vector<double> temp = m_data->getBuffer(); // retrieve current values from Flight Gear
    double val = temp[m_data->getAddressSpot().getSpot(script[index + 3])]; // get the value at given address
    m_data->addToSymbolTable(script[index], val); // update Symbol Table with new variable and its value
    return 5;
}
