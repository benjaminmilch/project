//
// Created by ben on 12/25/18.
//

#include "SleepCommand.h"
#include <unistd.h>

int SleepCommand::execute(vector<string> script, unsigned long index)
{
    sleep(stoi(script[index + 1])/1000); // sleep is in seconds, so divide by 1000 for milliseconds
    return 3;
}
