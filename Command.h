#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>

using namespace std;

class Command {
public:
    virtual void execute(vector<string> line) = 0;
    virtual void store(vector<string>line) = 0;
};

#endif // COMMAND_H
