#include <iostream>
#include "LoopCommand.h"
#include "ConditionCommand.h"
#include "PrintCommand.h"
#include "EqualsCommand.h"
#include "SleepCommand.h"

LoopCommand::LoopCommand(GlobalData *data)
{
    m_data = data;
}
int LoopCommand::execute(vector<string> script, unsigned long index)
{
    ConditionCommand condition_command = ConditionCommand(m_data); // loop's condition
    unsigned long condition = index; // use this index for executing the ConditionCommand
    unsigned long loop = index;
    unsigned long if_counter = 0;
    index = loop;
    while (script[loop] != "\n") {
        loop++;
    }
    loop++; // beginning index of the line following the condition of the loop
    vector<string> if_vector;
    while (condition_command.execute(script, condition) == 1) {
        index = loop;
        // run through each line of the loop, executing each command accordingly
        while (script[index] != "}") {
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
                while (script[index] != "}") {
                    if_vector.push_back(script[index]);
                    if_counter++;
                }
                index += if_counter;
            } else if (script[index] == "while") {
                LoopCommand loop_command = LoopCommand(m_data);
                index += loop_command.execute(script, index);
            }
        }
    }
    if (index == loop) { // count index place if the while loop was never executed
        while (script[index] != "}") {
            index++;
        }
    }
    return int(index - condition) + 2; // intentional casting to int for return value
}