#include "ConnectCommand.h"
#include "ValidateNumbers.h"
#include <iostream>

void ConnectCommand::setSocketAndPort(string socket, string port)
{
    m_socket.append(socket);
    m_port.append(port);
}
void ConnectCommand::execute()
{
    ValidateNumbers validator;
    if (validator.validateNumbers(m_port) && validator.validateSocket(m_socket)) {
        // port and socket are valid, need to connect client from socket to port


    } else {
        std::cout << "Syntax Error: Socket or Port received invalid input" << std::endl;
    }
}