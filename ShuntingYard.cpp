//
// Created by ben on 12/26/18.
//

#include "ShuntingYard.h"
#include <stack>
#include <queue>
#include "Div.h"
#include "Minus.h"
#include "Mul.h"
#include "Number.h"
#include "Plus.h"
#include "Neg.h"
#include "ExpressionGenerator.h"

ShuntingYard::ShuntingYard(GlobalData *data)
{
    m_data = data;
}
Expression* ShuntingYard::evaluateExpression(vector<string> expression)
{
    stack<string> operator_stack;
    stack<string> expression_stack;

    map<string, int> ranking; // operator rankings for shunting-yard algorithm
    ranking["("] = 0;
    ranking["{"] = 0;
    ranking["["] = 0;
    ranking["+"] = 1;
    ranking["-"] = 1;
    ranking["*"] = 2;
    ranking["/"] = 2;
    ranking[")"] = 3;
    ranking["}"] = 3;
    ranking["]"] = 3;

    ExpressionGenerator generator;

    vector<string>::iterator it; // loop to iterator through the entire vector
    for (it = expression.begin(); it != expression.end(); it++) {
        if (isOperator(*it)) {
            if (operator_stack.empty()) { // add operator to empty operator_stack
                operator_stack.push(*it);
            } else {
                if (ranking[*it] == 0) { // always add opening parenthesis to operator_stack
                    operator_stack.push(*it);
                } else if (ranking[*it] != 3) { // not a closing parenthesis
                    if (ranking[*it] > ranking[operator_stack.top()]) { // new operator has higher ranking, add to stack
                        operator_stack.push(*it);
                    } else {
                        // add operators to expression_stack until operator in operator_stack is less than or empty
                        while (ranking[*it] <= ranking[operator_stack.top()] || operator_stack.empty()) {
                            expression_stack.push(operator_stack.top());
                            operator_stack.pop();
                        }
                    }
                } else {
                    // remove operators from operator_stack to expression_stack until matching parenthesis
                    while (operator_stack.top() != parenthesisPair(*it)) {
                        expression_stack.push(operator_stack.top());
                        operator_stack.pop();
                    }
                    operator_stack.pop(); // remove the opening parenthesis
                }
            }
        } else { // always enqueue numbers
            if (!m_data->isExists(*it)) {
                expression_stack.push(*it); // constant number
            } else {
                expression_stack.push(to_string(m_data->getSymbolTable().find(*it)->second)); // defined variable
            }
        }
    }

    // add all the remaining operators to expression_stack until operator_stack is empty
    while (!operator_stack.empty()) {
        expression_stack.push(operator_stack.top());
        operator_stack.pop();
    }

    return generator.generateExpression(expressionTree(expression_stack));
}
bool ShuntingYard::isOperator(string symbol)
{
    return (symbol.find_first_of("+-*/({[)}]") != string::npos); // return true is operator symbol is present
}
string ShuntingYard::parenthesisPair(string parenthesis)
{
    if (parenthesis == ")") {
        return "(";
    } else if (parenthesis == "}") {
        return "{";
    } else {
        return "[";
    }
}
ExpressionTree* ShuntingYard::expressionTree(stack<string> &expression)
{
    ExpressionTree *tree = nullptr;
    // check throughout the statements
    if (!expression.empty()) {
        tree = new ExpressionTree(expression.top()); // top element is used to create new ExpressionTree
        expression.pop();
        // stack is not empty
        if (!expression.empty()) {
            // if the next element is not an operator and stack not empty, set the right child as the number
            if (!isOperator(expression.top())) {
                tree->setRight(new ExpressionTree(expression.top()));
                expression.pop();
                if (!expression.empty()) {
                    // if the next element is not an operator, set the left child as a number
                    if (!isOperator(expression.top())) {
                        tree->setLeft(new ExpressionTree(expression.top()));
                        expression.pop();
                    } else { // the next element is an operator, set the left child as a new (sub)tree
                        tree->setLeft(expressionTree(expression));
                    }
                }
            } else { // the next element is an operator, set the right child as a new (sub)tree
                tree->setRight(expressionTree(expression));
            }
        }
    }
    return tree;
}