#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>

using namespace std;

/****************************************************************
* Class Name: Command                                           *
* Constructor: No constructor (interface)                       *
* Class Functionality: Command Interface with single method     *
*   execute().                                                  *
****************************************************************/
class Command {
public:
    virtual int execute(vector<string> script, unsigned long index) = 0;
};

#endif // COMMAND_H
