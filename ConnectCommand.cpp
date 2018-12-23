#include "ConnectCommand.h"
#include "ValidateNumbers.h"
#include <iostream>
#include "Client.h"

void ConnectCommand::setSocketAndPort(string socket, string port)
{
    m_socket.append(socket);
    m_port.append(port);
}
void ConnectCommand::execute(vector<string> line)
{
    ValidateNumbers validator;
    setSocketAndPort(line[1], line[2]);
    if (validator.validateNumbers(m_port) && validator.validateSocket(m_socket)) {
        // port and socket are valid, need to connect client from socket to port
        openClient();
    } else {
        std::cout << "Syntax Error: Socket or Port received invalid input" << std::endl;
    }
}
void ConnectCommand::openClient()
{
    Client client(m_socket, stoi(m_port));
    client.connectToServer();
}