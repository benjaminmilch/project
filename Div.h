#ifndef PROJECT_DIV_H
#define PROJECT_DIV_H


#include "BinaryExpression.h"

/****************************************************************
* Class Name: Div                                               *
* Constructor: Two Expressions, left and right                  *
* Class Functionality: Calls upon the Expressions' calculate    *
*   and then divides the left by the right.                     *
****************************************************************/
class Div : public BinaryExpression{
public:
    Div(Expression *left, Expression *right); // constructor (members from super class: BinaryExpression)
    double calculate() override;
};


#endif //PROJECT_DIV_H