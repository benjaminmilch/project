#ifndef PROJECT_BINDCOMMAND_H
#define PROJECT_BINDCOMMAND_H

#include "Command.h"
#include "GlobalData.h"

/****************************************************************
* Class Name: BindCommand                                       *
* Constructor: Pointer to GlobalData                            *
* Class Functionality: This class updates the address table     *
*   with the new variable defined in the line.                  *
****************************************************************/
class BindCommand : public Command {
    GlobalData *m_data; // member
public:
    explicit BindCommand(GlobalData *data); // constructor
    int execute(vector<string> script, unsigned long index) override;
};


#endif //PROJECT_BINDCOMMAND_H
