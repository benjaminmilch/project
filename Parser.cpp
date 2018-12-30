#include <iostream>
#include "Parser.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "LoopCommand.h"
#include "IfCommand.h"
#include "EqualsCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"

Parser::Parser(GlobalData *data) {
    m_data = data;
    // create the Command objects to be added to the command map
    auto *open = new OpenServerCommand(data);
    auto *connect = new ConnectCommand(data);
    auto *var = new DefineVarCommand(data);
    auto *loop = new LoopCommand(data);
    auto *if_command = new IfCommand(data);
    auto *equals = new EqualsCommand(data);
    auto *print = new PrintCommand(data);
    auto *sleep = new SleepCommand();

    // each Command assigned to the map with its keyword
    m_command_map.insert({"openDataServer", open});
    m_command_map.insert({"connect", connect});
    m_command_map.insert({"var", var});
    m_command_map.insert({"while", loop});
    m_command_map.insert({"if", if_command});
    m_command_map.insert({"=", equals});
    m_command_map.insert({"print", print});
    m_command_map.insert({"sleep", sleep});
}

void Parser::parse(vector<string> script) {
    unsigned long index = 0;
    unsigned long end = script.size(); // stopping index
    vector<string> temp;
    copy(script.begin(), script.end(), back_inserter(temp));
    while (index < end - 1) { // loop through the entire script until
        if (temp[index].compare("openDataServer") == 0) {
            index += m_command_map[script[index]]->execute(script, index);
        } else if (temp[index].compare("connect") == 0) {
            index += m_command_map["connect"]->execute(script, index);
        } else if (temp[index].compare("var") == 0) {
            index += m_command_map["var"]->execute(script, index);
        } else if (temp[index].compare("while") == 0) {
            index += m_command_map["while"]->execute(script, index);
        } else if (temp[index].compare("if") == 0) {
            index += m_command_map["if"]->execute(script, index);
        } else if (temp[index].compare("print") == 0) {
            index += m_command_map["print"]->execute(script, index);
        } else if (temp[index].compare("sleep") == 0) {
            index += m_command_map["sleep"]->execute(script, index);
        } else {
            index += m_command_map["="]->execute(script, index);
        }
        while (m_data->isHalt());
    }
    m_data->closeSockets();
}