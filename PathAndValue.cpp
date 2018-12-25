//
// Created by ben on 12/25/18.
//

#include "PathAndValue.h"

PathAndValue::PathAndValue(string path)
{
    m_path.append(path);
    m_value = 0;
}
void PathAndValue::updateValue(double value)
{
    m_value = value;
}
string PathAndValue::getPath()
{
    return m_path;
}