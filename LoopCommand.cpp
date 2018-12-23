#include "LoopCommand.h"

void LoopCommand::addCommand(Command *command)
{
    m_commands.push_back(command);
}
void LoopCommand::execute()
{

}