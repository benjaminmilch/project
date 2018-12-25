#include "LoopCommand.h"

LoopCommand::LoopCommand()
{
    m_condition = false;
}
void LoopCommand::execute(vector<string> line)
{
    list<Command>::iterator i;
    while (m_condition){
        for (i = m_commands.begin(); i != m_commands.end(); i++){
            i->execute();
        }
    }
}
void LoopCommand::store(vector<string> line)
{
    if (!m_condition) {

    }
}