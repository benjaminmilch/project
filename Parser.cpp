#include "Parser.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "LoopCommand.h"

Parser::Parser()
{
    OpenServerCommand *open;
    ConnectCommand *connect;
    DefineVarCommand *define;
    LoopCommand *loop;

    m_command_map.insert({"openDataServer", open});
    m_command_map.insert({"connect", connect});
    m_command_map.insert({"var", define});
    m_command_map.insert({"while", loop});

    m_loop = false;
}
void Parser::parse(vector<string> line)
{
    if (!m_loop) {
        m_command_map.find(line[0])->second->store(line);
        m_loop = true;
    } else {
        if (line[0] != "}") {
            m_command_map.find("while")->second->store(line);
        } else {
            m_loop = false;
        }
    }
}