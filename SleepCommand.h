//
// Created by ben on 12/25/18.
//

#ifndef PROJECT_SLEEPCOMMAND_H
#define PROJECT_SLEEPCOMMAND_H

#include "Command.h"

class SleepCommand : public Command {
public:
    void execute() override;
    void store(vector<string> line) override;
};


#endif //PROJECT_SLEEPCOMMAND_H
