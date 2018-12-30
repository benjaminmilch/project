//
// Created by ben on 12/26/18.
//

#include "ExpressionTree.h"

ExpressionTree::ExpressionTree(string& node)
{
    m_node = node;
    // initialize the children to null pointers
    m_left = nullptr;
    m_right = nullptr;
}
void ExpressionTree::setLeft(ExpressionTree *left)
{
    m_left = left;
}
void ExpressionTree::setRight(ExpressionTree *right)
{
    m_right = right;
}
ExpressionTree* ExpressionTree::getLeft()
{
    return m_left;
}
ExpressionTree* ExpressionTree::getRight()
{
    return m_right;
}
string ExpressionTree::getNode()
{
    return m_node;
}