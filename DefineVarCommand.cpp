#include "DefineVarCommand.h"
#include "BindOrEquals.h"

DefineVarCommand::DefineVarCommand(GlobalData *data)
{
    m_data = data;
}
int DefineVarCommand::execute(vector<string> script, unsigned long index) {
    BindOrEquals factory(m_data);
    vector<string> line;
    unsigned long temp_index = index + 1; // skip the "var" string in the vector
    while (script[temp_index] != "\n") { // store just the variable definition line
        line.push_back(script[temp_index]);
        temp_index++;
    }
    line.emplace_back("\n");
    Command *var_command = factory.getCommand(line); // receive BindCommand or EqualsCommand
    return var_command->execute(line, 0) + 1;
}