#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H
#include "DataReaderServer.h"
#include "Command.h"
#include "GlobalData.h"
#include <string>

/****************************************************************
* Class Name: OpenServerCommand                                 *
* Constructor: Pointer to GlobalData                            *
* Class Functionality: Opens the server socket and runs it.     *
****************************************************************/
class OpenServerCommand : public Command {
    GlobalData* m_globalData; // member
public:
    explicit OpenServerCommand(GlobalData *data); // constructor
    int execute(vector<string> script, unsigned long index) override; // open the server socket to run in background
};


#endif //PROJECT_OPENSERVERCOMMAND_H
