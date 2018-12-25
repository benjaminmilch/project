#ifndef PROJECT_LOOPCOMMAND_H
#define PROJECT_LOOPCOMMAND_H

#include "Command.h"
#include <list>
#include "ConditionCommand.h"

using namespace std;

class LoopCommand : public Command{
    list<Command> m_commands;
    ConditionCommand m_condition;
public:
    void execute() override;
    void store(vector<string> line) override;
};


#endif //PROJECT_LOOPCOMMAND_H
