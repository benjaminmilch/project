#ifndef PROJECT_BINARYEXPRESSION_H
#define PROJECT_BINARYEXPRESSION_H

#include "Expression.h"

/****************************************************************
* Class Name: BinaryExpression                                  *
* Constructor: Two Expressions, left and right                  *
* Class Functionality: Super class used for construction of all *
*   its children classes to prevent duplicate code.             *
****************************************************************/
class BinaryExpression : public Expression {
protected:
    Expression *m_left, *m_right; // member
public:
    BinaryExpression(Expression *left, Expression *right); // constructor

    // getter methods to retrieve the left and right expressions
    Expression* getLeft() const;
    Expression* getRight() const;
};
#endif //PROJECT_BINARYEXPRESSION_H
