#ifndef PROJECT_VALIDATENUMBERS_H
#define PROJECT_VALIDATENUMBERS_H

#include <string>

/****************************************************************
* Class Name: ValidateNumbers                                   *
* Constructor: Default constructor                              *
* Class Functionality: This class validates the inputted        *
*   numbers for socket ports and IP addresses.                  *
****************************************************************/
class ValidateNumbers {
public:
    bool validateNumbers(std::string number); // validate socket number
    bool validateIP(std::string IP); // validate IP address
};


#endif //PROJECT_VALIDATENUMBERS_H
