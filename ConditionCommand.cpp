//
// Created by ben on 12/25/18.
//

#include <iostream>
#include "ConditionCommand.h"
#include "ShuntingYard.h"

ConditionCommand::ConditionCommand(GlobalData *data)
{
    m_data = data;
}
int ConditionCommand::execute(vector<string> script, unsigned long index) {
    double first, second;
    vector<string> temp;
    unsigned long end_index = index;
    unsigned long temp_index = index + 1; // starting index without the condition word (if/while)

    while (script[end_index] != "{") { // locate the end of the condition's index
        end_index++;
    }

    // the first operand of the condition is an existing variable and not part of an Expression
    if (m_data->isExists(script[temp_index]) && conditionCheck(script, temp_index + 1)) {
        first = m_data->getSymbolTable().at(script[temp_index]);
    } else { // the first operand is an Expression
        first = createExpression(script, temp_index, locateOperator(script, temp_index, end_index))->calculate();
    }
    // the second operand of the condition is an existing variable and not part of an Expression
    if (m_data->isExists(script[end_index - 1]) && conditionCheck(script, end_index - 2)) {
        second = m_data->getSymbolTable().at(script[end_index - 1]);
    } else { // the second operand is an Expression
        second = createExpression(script, locateOperator(script, temp_index, end_index) + 1, end_index)->calculate();
    }

    // return the conditions result (1 = true, 0 = false)
    if (checkCondition(script, temp_index, end_index, first, second)) {
        return 1;
    } else {
        return 0;
    }
}
unsigned long ConditionCommand::locateOperator(vector<string> script, unsigned long start, unsigned long end)
{
    unsigned long i;
    for (i = start; i < end; i++) {
        if (conditionCheck(script, i)) {
            break;
        }
    }
    return i;
}
Expression *ConditionCommand::createExpression(vector<string> script, unsigned long begin, unsigned long end)
{
    vector<string> expression;
    ShuntingYard shunt(m_data);

    for (unsigned long i = begin; i < end; i++) {
        expression.push_back(script[i]);
    }
    return shunt.evaluateExpression(expression);
}
bool ConditionCommand::conditionCheck(vector<string> script, unsigned long index)
{
    return script[index].find_first_of("><=") != string::npos;
}
bool ConditionCommand::checkCondition(vector<string> script, unsigned long start, unsigned long end,
                                      double first, double second) {
    // return the result of the comparison
    string op = script[locateOperator(script, start, end)];
    if (op == "<") {
        return first < second;
    } else if (op == ">") {
        return first > second;
    } else if (op == "==") {
        return first == second;
    } else if (op == "!=") {
        return first != second;
    } else if (op == "<=") {
        return first <= second;
    } else if (op == ">=") {
        return first >= second;
    } else {
        perror("ERROR: invalid operator");
        exit(1);
    }
}
