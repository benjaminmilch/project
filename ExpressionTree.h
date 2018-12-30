//
// Created by ben on 12/26/18.
//

#ifndef PROJECT_EXPRESSIONTREE_H
#define PROJECT_EXPRESSIONTREE_H

#include "string"

using namespace std;

/****************************************************************
* Class Name: ExpressionTree                                    *
* Constructor: String by reference                              *
* Class Functionality: This class is an binary tree that        *
*   represents a mathematical expression. Each node has a right *
*   and left child, and is built recursively.                   *
****************************************************************/
class ExpressionTree {
    // members
    string m_node;
    ExpressionTree *m_left, *m_right;
public:
    explicit ExpressionTree(string& node); // constructor

    // set the left and right children nodes
    void setLeft(ExpressionTree *left);
    void setRight(ExpressionTree *right);

    // get the left and right children nodes
    ExpressionTree* getLeft();
    ExpressionTree* getRight();

    // return the string representing THIS node
    string getNode();
};


#endif //PROJECT_EXPRESSIONTREE_H
