//
// Created by ben on 12/25/18.
//

#ifndef PROJECT_CONDITIONCOMMAND_H
#define PROJECT_CONDITIONCOMMAND_H

#include "Command.h"
#include "Expression.h"

class ConditionCommand : public Command{
    Expression *m_left, *m_right;
    string m_operator;
public:
    void execute() override;
    void store(vector<string> line) override;
};


#endif //PROJECT_CONDITIONCOMMAND_H
