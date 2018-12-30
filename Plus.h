#ifndef PROJECT_PLUS_H
#define PROJECT_PLUS_H

#include "BinaryExpression.h"

/****************************************************************
* Class Name: Plus                                              *
* Constructor: Two Expressions, left and right                  *
* Class Functionality: Calculates the left and right expressions*
*   with "+" operation connecting them. Returns the result.     *
****************************************************************/
class Plus : public BinaryExpression {
public:
    Plus(Expression *left, Expression *right); // constructor (members from super class: BinaryExpression)
    double calculate() override;
};


#endif //PROJECT_PLUS_H
