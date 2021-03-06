#ifndef PROJECT_LOOPCOMMAND_H
#define PROJECT_LOOPCOMMAND_H

#include "Command.h"
#include "GlobalData.h"

/****************************************************************
* Class Name: LoopCommand                                       *
* Constructor: Pointer to GlobalData                            *
* Class Functionality: Sets a ConditionCommand for the loop by  *
*   creating a new ConditionCommand object. This object is used *
*   for the loop's condition to stop or continue. Each line in  *
*   the script is read, with each line containing one Command   *
*   object to be executed after each iteration.                 *
****************************************************************/
class LoopCommand : public Command{
    GlobalData *m_data; // member
public:
    explicit LoopCommand(GlobalData *data); // constructor
    int execute(vector<string> script, unsigned long index) override;
};


#endif //PROJECT_LOOPCOMMAND_H
