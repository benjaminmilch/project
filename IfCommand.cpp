//
// Created by ben on 12/26/18.
//

#include "IfCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "EqualsCommand.h"

IfCommand::IfCommand(GlobalData *data)
{
    m_data = data;
}
int IfCommand::execute(vector<string> script, unsigned long index)
{
    ConditionCommand condition_command = ConditionCommand(m_data); // Condition of the if statement
    unsigned long condition = index;
    unsigned long while_counter = 0;
    while (script[index] != "\n") {
        index++;
    }
    index++; // starting index of the commands within the if statement
    vector<string> while_vector;
    if (condition_command.execute(script, condition) == 1) { // enter if statement if condition is true
        while (script[index] != "}") { // loop through each row (only ONCE) executing each command
            if (script[index] == "print") {
                PrintCommand print = PrintCommand(m_data);
                index += print.execute(script, index);
            } else if (script[index] == "sleep") {
                SleepCommand sleep = SleepCommand();
                index += sleep.execute(script, index);
            } else if (m_data->isExists(script[index])) {
                EqualsCommand equals = EqualsCommand(m_data);
                index +=  equals.execute(script, index);
            } else if (script[index] == "if") {
                IfCommand if_command = IfCommand(m_data);
                index += if_command.execute(script, index);
            } else if (script[index] == "while") {
                while (script[index] != "}") {
                    while_vector.push_back(script[index]);
                    while_counter++;
                }
            }
        }
    } else { // condition is false, loop through until the end of the if statement to return next starting index
        while (script[index] != "}") {
            index++;
        }
    }
    return int(index - condition) + 2; // intentional casting to int for return value
}