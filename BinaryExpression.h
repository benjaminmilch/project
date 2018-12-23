#ifndef PROJECT_BINARYEXPRESSION_H
#define PROJECT_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression *m_left, *m_right;
public:
    BinaryExpression(Expression *left, Expression *right);
    virtual Expression* getLeft() const = 0;
    virtual Expression* getRight() const = 0;
};
#endif //PROJECT_BINARYEXPRESSION_H
