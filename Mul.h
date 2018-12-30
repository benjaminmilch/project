#ifndef PROJECT_MUL_H
#define PROJECT_MUL_H


#include "BinaryExpression.h"

/****************************************************************
* Class Name: Mul                                               *
* Constructor: Two Expressions, left and right                  *
* Class Functionality: Calls upon the Expressions to calculate  *
*   and then multiplies their results together.                 *
****************************************************************/
class Mul : public BinaryExpression{
public:
    explicit Mul(Expression *left, Expression *right); // constructor (members from super class: BinaryExpression)
    double calculate() override;
};


#endif //PROJECT_MUL_H