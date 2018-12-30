//
// Created by ben on 12/25/18.
//

#ifndef PROJECT_EQUALSCOMMAND_H
#define PROJECT_EQUALSCOMMAND_H

#include "Command.h"
#include "GlobalData.h"

/****************************************************************
* Class Name: EqualsCommand                                     *
* Constructor: Pointer to GlobalData                            *
* Class Functionality: This class determines the type of equals *
*   expression to handle: a variable equal to another variable  *
*   or a variable equal to an expression. It uses ShuntYard     *
*   class to evaluate the expressions. At the end of evaluation *
*   EqualsCommand updates the SymbolTable stored in GlobalData. *
****************************************************************/
class EqualsCommand : public Command {
    GlobalData *m_data; // member
public:
    explicit EqualsCommand(GlobalData *data); // constructor

    int execute(vector<string> script, unsigned long index) override;

    // helper methods to determine if a variable exists in the SymbolTable and if the address table
    // (to determine if the variable will need to be used to update Flight Gear, or just a random variable
    // used for calculations throughout the program)
    bool variableExists(string variable);
    bool addressExists(string &variable);

    void update(string variable); // updates the system of variable value changes
};


#endif //PROJECT_EQUALSCOMMAND_H
