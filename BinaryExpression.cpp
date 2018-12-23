#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *left, Expression *right)
{
    m_left = left;
    m_right = right;
}
Expression* BinaryExpression::getLeft() const {
    return m_left;
}
Expression* BinaryExpression::getRight() const {
    return m_right;
}