//
// Created by ben on 12/27/18.
//

#ifndef PROJECT_NEG_H
#define PROJECT_NEG_H

#include "Expression.h"
#include <string>

using namespace std;

/****************************************************************
* Class Name: Neg                                               *
* Constructor: Expression                                       *
* Class Functionality: Negates the Expression member by calling *
*   it's Expression member's calculate, then multiplying by -1. *
****************************************************************/
class Neg : public Expression {
    Expression *m_value; // member
public:
    explicit Neg(Expression *expression); // constructor
    double calculate() override;
};


#endif //PROJECT_NEG_H
