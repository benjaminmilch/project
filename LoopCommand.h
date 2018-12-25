#ifndef PROJECT_LOOPCOMMAND_H
#define PROJECT_LOOPCOMMAND_H

#include "Command.h"
#include <list>

class LoopCommand : public Command{
    std::list<Command> m_commands;
    bool m_condition;
public:
    LoopCommand();
    void execute(vector<string> line) override;
    void store(vector<string> line) override;
};


#endif //PROJECT_LOOPCOMMAND_H
