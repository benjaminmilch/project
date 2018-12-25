#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include "Command.h"
#include <string>

using namespace std;

class OpenServerCommand : public Command {
    string m_port, m_freq;
public:
    void execute(vector<string> line) override;
    void store(vector<string> line) override;
    void openServer();
};


#endif //PROJECT_OPENSERVERCOMMAND_H
