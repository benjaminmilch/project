#ifndef PROJECT_LOOPCOMMAND_H
#define PROJECT_LOOPCOMMAND_H

#include "Command.h"
#include <list>

class LoopCommand {
    std::list<Command> m_commands;
public:
    void addCommand(Command command);
    void execute();
};


#endif //PROJECT_LOOPCOMMAND_H
