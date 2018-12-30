//
// Created by ben on 12/26/18.
//

#ifndef PROJECT_EXPRESSIONGENERATOR_H
#define PROJECT_EXPRESSIONGENERATOR_H

#include "ExpressionTree.h"
#include "Expression.h"

/****************************************************************
* Class Name: ExpressionGenerator                               *
* Constructor: Default constructor                              *
* Class Functionality: This class generates an Expression by a  *
*   factory-like setup.                                         *
****************************************************************/
class ExpressionGenerator {
public:
    Expression* generateExpression(ExpressionTree *tree); // returns the newly created Expression
    int expressionType(ExpressionTree *tree); // determines the Expression type (by operator)
};


#endif //PROJECT_EXPRESSIONGENERATOR_H
