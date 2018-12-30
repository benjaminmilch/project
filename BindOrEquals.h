//
// Created by ben on 12/27/18.
//

#ifndef PROJECT_BINDOREQUALS_H
#define PROJECT_BINDOREQUALS_H

#include "Command.h"
#include "GlobalData.h"

/****************************************************************
* Class Name: BindOrEquals                                      *
* Constructor: Pointer to the GlobalData                        *
* Class Functionality: This class is used to determine if the   *
*   line being checked is a "bind" type of variable definition  *
*   or an "=" (without "bind") variable definition.             *
****************************************************************/
class BindOrEquals {
    GlobalData *m_data; // member
public:
    explicit BindOrEquals(GlobalData *data); // constructor

    Command* getCommand(vector<string> line); // Return the appropriate Command type
    bool isBind(vector<string> line); // locate if "bind" is in the line
    bool isEqual(vector<string> line); // locates if "=" is in the line

};


#endif //PROJECT_BINDOREQUALS_H
