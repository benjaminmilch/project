//
// Created by ben on 12/25/18.
//

#ifndef PROJECT_SLEEPCOMMAND_H
#define PROJECT_SLEEPCOMMAND_H

#include "Command.h"
#include "GlobalData.h"

/****************************************************************
* Class Name: SleepCommand                                      *
* Constructor: Default constructor                              *
* Class Functionality: This class causes the program to sleep   *
*   for the inputted amount of time in milliseconds.            *
****************************************************************/
class SleepCommand : public Command {
    GlobalData *m_data;
public:
    int execute(vector<string> script, unsigned long index) override;
};


#endif //PROJECT_SLEEPCOMMAND_H
