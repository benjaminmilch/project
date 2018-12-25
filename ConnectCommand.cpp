#include "ConnectCommand.h"
#include "ValidateNumbers.h"
#include <iostream>
#include "Client.h"

void ConnectCommand::execute(vector<string> line)
{
    ValidateNumbers validator;
    if (validator.validateNumbers(m_port) && validator.validateIP(m_IP)) {
        // port and socket are valid, need to connect client from socket to port
        openClient();
    } else {
        std::cout << "Syntax Error: Socket or Port received invalid input" << std::endl;
    }
}
void ConnectCommand::store(vector<string> line)
{
    m_IP.append(line[1]);
    m_port.append(line[2]);
}
void ConnectCommand::openClient()
{

}