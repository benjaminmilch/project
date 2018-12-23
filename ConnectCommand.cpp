#include "ConnectCommand.h"
#include "ValidateNumbers.h"
#include <iostream>
#include "Client.h"

ConnectCommand::ConnectCommand(vector<string> line)
{
    m_socket.append(line[1]);
    m_port.append(line[2]);
}
void ConnectCommand::execute()
{
    ValidateNumbers validator;
    if (validator.validateNumbers(m_port) && validator.validateSocket(m_socket)) {
        // port and socket are valid, need to connect client from socket to port
        openClient();
    } else {
        std::cout << "Syntax Error: Socket or Port received invalid input" << std::endl;
    }
}
void ConnectCommand::openClient()
{

}