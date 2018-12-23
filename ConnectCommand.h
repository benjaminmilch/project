#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include "Command.h"
#include <string>

using namespace std;

class ConnectCommand : public Command {
    std::string m_socket, m_port;
public:
    ConnectCommand();
    void setSocketAndPort(string socket, string port);
    void execute();
};


#endif //PROJECT_CONNECTCOMMAND_H
