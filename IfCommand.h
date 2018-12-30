//
// Created by ben on 12/26/18.
//

#ifndef PROJECT_IFCOMMAND_H
#define PROJECT_IFCOMMAND_H

#include "Command.h"
#include "GlobalData.h"
#include "ConditionCommand.h"

/****************************************************************
* Class Name: IfCommand                                         *
* Constructor: Pointer to GlobalData                            *
* Class Functionality: Sets a ConditionCommand for the if by    *
*   creating a new ConditionCommand object. This object is used *
*   for the if's condition to skip or continue. Each line in    *
*   the script is read, with each line containing one Command   *
*   object to be executed after each iteration.                 *
****************************************************************/
class IfCommand : public Command {
GlobalData *m_data; // member
public:
    explicit IfCommand(GlobalData *data); // constructor
    int execute(vector<string> script, unsigned long index) override;
};


#endif //PROJECT_IFCOMMAND_H
