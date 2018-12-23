#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include "Command.h"
#include <string>

using namespace std;

class ConnectCommand : public Command {
    string m_socket, m_port;
public:
    ConnectCommand(vector<string> line);
    void execute() override;
    void openClient();
};


#endif //PROJECT_CONNECTCOMMAND_H
