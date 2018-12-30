#include "ConnectCommand.h"
#include "ValidateNumbers.h"
#include <iostream>
#include "Client.h"

ConnectCommand::ConnectCommand(GlobalData *globalData)
{
    m_globalData = globalData;
}
int ConnectCommand::execute(vector<string> script, unsigned long index)
{
    ValidateNumbers validator;
    if (validator.validateNumbers(script[index + 2]) && validator.validateIP(script[index + 1])) {
        // port and socket are valid, need to connect client from socket to port
        Client client = Client(script[index + 1].c_str(), stoi(script[index + 2]), m_globalData);
        client.connectToServer();
    } else {
        std::cout << "Syntax Error: Socket or Port received invalid input" << std::endl;
    }
    return 4;
}

