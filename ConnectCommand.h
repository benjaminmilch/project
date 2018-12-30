#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include "Command.h"
#include "GlobalData.h"
#include <string>

/****************************************************************
* Class Name: ConnectCommand                                    *
* Constructor: Pointer to GlobalData                            *
* Class Functionality: This class is used to connect the client *
*   socket at their IP address with the server socket.          *
****************************************************************/
class ConnectCommand : public Command {
    GlobalData* m_globalData; // member
public:
    explicit ConnectCommand(GlobalData *globalData); // constructor
    int execute(vector<string> script, unsigned long index) override;

};


#endif //PROJECT_CONNECTCOMMAND_H
