#include "OpenServerCommand.h"
#include "ValidateNumbers.h"
#include <iostream>
#include <thread>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

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
        thread t1(&OpenServerCommand::openServer, this);
    } else {
        perror("Syntax Error: Port or Frequency received invalid input");
        exit(0);
    }
}
void OpenServerCommand::openServer()
{
    int server = socket(AF_INET, SOCK_STREAM, 0);
    if (server < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
}