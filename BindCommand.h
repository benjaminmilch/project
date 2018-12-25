//
// Created by ben on 12/25/18.
//

#ifndef PROJECT_BINDCOMMAND_H
#define PROJECT_BINDCOMMAND_H

#include "Command.h"

class BindCommand : public Command {
public:
    void execute() override;
    void store(vector<string> line) override;
};


#endif //PROJECT_BINDCOMMAND_H
