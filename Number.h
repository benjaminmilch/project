#ifndef PROJECT_NUMBER_H
#define PROJECT_NUMBER_H


#include "Expression.h"
#include <string>

using namespace std;

/****************************************************************
* Class Name: Number                                            *
* Constructor: String                                           *
* Class Functionality: Returns the double value of the string   *
*   number received.                                            *
****************************************************************/
class Number : public Expression{
    double m_value;
public:
    explicit Number(string val);
    double calculate() override;
};


#endif //PROJECT_NUMBER_H