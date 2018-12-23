#include "Parser.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"

Parser::Parser()
{
    OpenServerCommand *open;
    ConnectCommand *connect;
    DefineVarCommand *define;

    m_command_map.insert({"openDataServer", open});
    m_command_map.insert({"connect", connect});
    m_command_map.insert({"var", define});
}
void Parser::parse(vector<string> line)
{
    m_command_map.find(line[0])->second->execute(line);
}