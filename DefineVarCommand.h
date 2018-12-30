#ifndef PROJECT_DEFINEVARCOMMAND_H
#define PROJECT_DEFINEVARCOMMAND_H

#include "Command.h"
#include <map>
#include "GlobalData.h"

/****************************************************************
* Class Name: DefineVarCommand                                  *
* Constructor: Pointer to GlobalData                            *
* Class Functionality: This class defines new variables in the  *
*   program. It uses either the EqualsCommand or BindCommand    *
*   classes accordingly.
****************************************************************/
class DefineVarCommand : public Command{
    GlobalData *m_data; // member
public:
    explicit DefineVarCommand(GlobalData *data); // constructor
    int execute(vector<string> script, unsigned long index) override;
};


#endif //PROJECT_DEFINEVARCOMMAND_H