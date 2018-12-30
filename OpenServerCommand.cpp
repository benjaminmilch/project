#include "OpenServerCommand.h"
#include "ValidateNumbers.h"

#include <iostream>
#include <thread>


OpenServerCommand::OpenServerCommand(GlobalData *data) {
    m_globalData = data;
}
int OpenServerCommand::execute(vector<string> script, unsigned long index) {
    DataReaderServer drs = DataReaderServer(m_globalData);
    ValidateNumbers validator;
    // validate the socket numbers and frequency, then open the server in the background by DataReaderServer
    if (validator.validateNumbers(script[index + 1]) && validator.validateNumbers(script[index + 2])) {
        drs.runServer(stoi(script[index + 1]), stoi(script[index + 2]));
    }
    return 4;
}
