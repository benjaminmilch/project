//
// Created by ben on 12/25/18.
//

#ifndef PROJECT_CONDITIONCOMMAND_H
#define PROJECT_CONDITIONCOMMAND_H

#include "Command.h"
#include "Expression.h"
#include "GlobalData.h"

/****************************************************************
* Class Name: ConditionCommand                                  *
* Constructor: Pointer to GlobalData                            *
* Class Functionality: This class receives a line with a single *
*   condition present, based on the operators "<, >, =" and all *
*   allowed combinations of them for C++ comparisons. Returns 1 *
*   if the expression is true and 0 if it is false;             *
****************************************************************/
class ConditionCommand : public Command{
    GlobalData *m_data; // member
public:
    explicit ConditionCommand(GlobalData *data); // constructor

    int execute(vector<string> script, unsigned long index) override;

    // helper methods for locating the operator, creating Expressions, and validating the condition
    unsigned long locateOperator(vector<string> script, unsigned long index, unsigned long end_index);
    Expression* createExpression(vector<string> script, unsigned long begin, unsigned long end);
    bool conditionCheck(vector<string> script, unsigned long index);
    bool checkCondition(vector<string> script, unsigned long start, unsigned long end, double first, double second);
};


#endif //PROJECT_CONDITIONCOMMAND_H
