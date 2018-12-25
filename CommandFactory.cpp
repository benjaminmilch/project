//
// Created by ben on 12/25/18.
//

#include "CommandFactory.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "BindCommand.h"
#include "EqualsCommand.h"
#include "ConditionCommand.h"
#include "LoopCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"


Command* CommandFactory::getCommand(string command_type)
{
    if (command_type == "openDataServer") {
        return new OpenServerCommand();
    } else if (command_type == "connect") {
        return new ConnectCommand();
    } else if (command_type == "var") {
        return new DefineVarCommand();
    } else if (command_type == "bind") {
        return new BindCommand();
    } else if (command_type == "=") {
        return new EqualsCommand();
    } else if (command_type == "while") {
        return new LoopCommand();
    } else if (command_type == "if") {
        return new ConditionCommand();
    } else if (command_type == "print") {
        return new PrintCommand();
    } else if (command_type == "sleep") {
        return new SleepCommand();
    } else {
        perror("ERROR: invalid command type");
        exit(1);
    }
}