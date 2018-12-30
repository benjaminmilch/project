//
// Created by ben on 12/26/18.
//

#include "ExpressionGenerator.h"
#include "Div.h"
#include "Minus.h"
#include "Mul.h"
#include "Plus.h"
#include "Number.h"
#include "Neg.h"

Expression* ExpressionGenerator::generateExpression(ExpressionTree *tree)
{
    switch(expressionType(tree))
    {
        case 1:
            return new Plus(generateExpression(tree->getLeft()), generateExpression(tree->getRight()));
        case 2:
            return new Minus(generateExpression(tree->getLeft()), generateExpression(tree->getRight()));
        case 3:
            return new Mul(generateExpression(tree->getLeft()), generateExpression(tree->getRight()));
        case 4:
            return new Div(generateExpression(tree->getLeft()), generateExpression(tree->getRight()));
        case 5:
            return new Neg(generateExpression(tree->getRight()));
        default:
            return new Number(tree->getNode());
    }
}
int ExpressionGenerator::expressionType(ExpressionTree *tree)
{
    // return a corresponding value for each Expression type based on the operator
    if (tree->getNode() == "+") {
        return 1;
    } else if (tree->getNode() == "-") {
        if (tree->getLeft() == nullptr) { // Neg(ate) Expression has no left child
            return 5;
        } else { // Minus Expression has left and right children
            return 2;
        }
    } else if (tree->getNode() == "*") {
        return 3;
    } else if (tree->getNode() == "/") {
        return 4;
    } else {
        return 0;
    }
}