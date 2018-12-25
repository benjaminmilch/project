#include "LoopCommand.h"

void LoopCommand::execute()
{

}
void LoopCommand::store(vector<string> line)
{
    if (line[0] == "while") {
        m_condition.store(line);
    } else { // add commands to the loops dynamic command list

    }
}