#include "Parser.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"

Parser::Parser()
{
    OpenServerCommand *open;
    ConnectCommand *connect;

    m_command_map.insert({"openDataServer", open});
    m_command_map.insert({"connect", connect});
}
void Parser::parse(vector<string> line)
{
    m_command_map.find(line[0])->second->execute(line);
}