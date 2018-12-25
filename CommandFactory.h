//
// Created by ben on 12/25/18.
//

#ifndef PROJECT_COMMANDFACTORY_H
#define PROJECT_COMMANDFACTORY_H

#include "Command.h"

class CommandFactory {
public:
    Command* getCommand(string command_type);
};


#endif //PROJECT_COMMANDFACTORY_H
