#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include "Command.h"
#include <string>

using namespace std;

class ConnectCommand : public Command {
    string m_socket, m_port;
public:
    ConnectCommand();
    void setSocketAndPort(string socket, string port);
    void execute(vector<string> line) override;
    void openClient();
};


#endif //PROJECT_CONNECTCOMMAND_H
