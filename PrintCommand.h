//
// Created by ben on 12/25/18.
//

#ifndef PROJECT_PRINTCOMMAND_H
#define PROJECT_PRINTCOMMAND_H

#include "Command.h"
#include "GlobalData.h"

/****************************************************************
* Class Name: PrintCommand                                      *
* Constructor: Pointer to GlobalData                            *
* Class Functionality: Prints either a variable's value or a    *
*   string to the screen.                                       *
****************************************************************/
class PrintCommand : public Command {
    // member
    GlobalData *m_data;
public:
    explicit PrintCommand(GlobalData *data); // constructor
    int execute(vector<string> script, unsigned long index) override; // print function
};


#endif //PROJECT_PRINTCOMMAND_H
