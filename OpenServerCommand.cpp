#include "OpenServerCommand.h"
#include "ValidateNumbers.h"
#include <iostream>
#include <thread>
#include "Server.h"

void OpenServerCommand::setPortAndFreq(string port, string freq)
{
    m_port.append(port);
    m_freq.append(freq);
}
void OpenServerCommand::execute(vector<string> line)
{
    ValidateNumbers validator;
    setPortAndFreq(line[1], line[2]);
    if (validator.validateNumbers(m_port) && validator.validateNumbers(m_freq)) {
        // port and freq are valid, need to open the server port
        Server server(stod(m_port));
        server.start();
        thread t1(&OpenServerCommand::openServer, this);
    } else {
        perror("Syntax Error: Port or Frequency received invalid input");
        exit(0);
    }
}
void OpenServerCommand::openServer()
{

}