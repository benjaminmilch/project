#include "OpenServerCommand.h"
#include "ValidateNumbers.h"
#include <iostream>
#include <thread>
#include "Server.h"

void OpenServerCommand::execute(vector<string> line)
{
    ValidateNumbers validator;
    if (validator.validateNumbers(m_port) && validator.validateNumbers(m_freq)) {
        // port and freq are valid, need to open the server port
        thread t1(&OpenServerCommand::openServer, this);
    } else {
        perror("Syntax Error: Port or Frequency received invalid input");
        exit(0);
    }
}
void OpenServerCommand::store(vector<string> line)
{
    m_port.append(line[1]);
    m_freq.append(line[2]);
}
void OpenServerCommand::openServer()
{
    Server server(stod(m_port));
    server.start();
}