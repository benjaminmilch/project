#ifndef PROJECT_MINUS_H
#define PROJECT_MINUS_H


#include "BinaryExpression.h"

/****************************************************************
* Class Name: Minus                                             *
* Constructor: Two Expressions, left and right                  *
* Class Functionality: Calls upon the Expressions' calculate    *
*   and then subtracts the left from the right.                 *
****************************************************************/
class Minus : public BinaryExpression{
public:
    Minus(Expression *left, Expression *right); // constructor (members from super class: BinaryExpression)
    double calculate() override;
};


#endif //PROJECT_MINUS_H
