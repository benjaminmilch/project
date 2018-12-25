//
// Created by ben on 12/25/18.
//

#ifndef PROJECT_EQUALSCOMMAND_H
#define PROJECT_EQUALSCOMMAND_H

#include "Command.h"

class EqualsCommand : public Command {
public:
    void execute() override;
    void store(vector<string> line) override;
};


#endif //PROJECT_EQUALSCOMMAND_H
