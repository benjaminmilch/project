//
// Created by ben on 12/26/18.
//

#ifndef PROJECT_SHUNTINGYARD_H
#define PROJECT_SHUNTINGYARD_H

#include "Expression.h"
#include "GlobalData.h"
#include <vector>
#include <string>
#include <stack>
#include "ExpressionTree.h"

using namespace std;

/****************************************************************
* Class Name: ShuntingYard                                      *
* Constructor: Pointer to GlobalData                            *
* Class Functionality: This class applies the Shunting-yard     *
*   algorithm to create an Expression object from the vector of *
*   strings it receives as a parameter. This class makes use of *
*   a binary tree that each node is either an operator or       *
*   number, called ExpressionTree.                              *
****************************************************************/
class ShuntingYard {
    GlobalData *m_data; // member
public:
    explicit ShuntingYard(GlobalData *data); // constructor

    Expression* evaluateExpression(vector<string> expression); // first evaluation of the expression
    bool isOperator(string symbol); // determines if the string is an operator symbol
    string parenthesisPair(string parenthesis); // returns the parenthesis pair to the received closing parenthesis
    ExpressionTree* expressionTree(stack<string> &expression); // creates the ExpressionTree recursively
};


#endif //PROJECT_SHUNTINGYARD_H
