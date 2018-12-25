//
// Created by ben on 12/25/18.
//

#ifndef PROJECT_PRINTCOMMAND_H
#define PROJECT_PRINTCOMMAND_H

#include "Command.h"

class PrintCommand : public Command {
public:
    void execute() override;
    void store(vector<string> line) override;
};


#endif //PROJECT_PRINTCOMMAND_H
