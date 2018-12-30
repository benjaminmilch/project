//
// Created by ben on 12/27/18.
//

#include "BindOrEquals.h"
#include "BindCommand.h"
#include "EqualsCommand.h"

BindOrEquals::BindOrEquals(GlobalData *data)
{
    m_data = data;
}
Command* BindOrEquals::getCommand(vector<string> line)
{
    // return a new Command based on the "bind" and/or "=" check. The "bind" check comes first because it
    // takes precedent over the "=" type of variable definition
    if (isBind(line)) {
        return new BindCommand(m_data);
    } else if (isEqual(line)){
        return new EqualsCommand(m_data);
    } else {
        perror("ERROR: invalid command type");
        exit(1);
    }
}
bool BindOrEquals::isBind(vector<string> line)
{
    for (const string &word : line)
    {
        if (word == "bind"){
            return true;
        }
    }
    return false;
}
bool BindOrEquals::isEqual(vector<string> line)
{
    for (const string &word : line)
    {
        if (word == "=") {
            return true;
        }
    }
    return false;
}