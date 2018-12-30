//
// Created by ben on 12/27/18.
//

#include "Neg.h"

Neg::Neg(Expression *expression)
{
    m_value = expression;
}
double Neg::calculate()
{
    return m_value->calculate() * (-1);
}