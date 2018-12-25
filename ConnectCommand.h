#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include "Command.h"
#include <string>

using namespace std;

class ConnectCommand : public Command {
    string m_IP, m_port;
public:
    void execute(vector<string> line) override;
    void store(vector<string> line) override;
    void openClient();
};


#endif //PROJECT_CONNECTCOMMAND_H
