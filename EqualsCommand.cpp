//
// Created by ben on 12/25/18.
//

#include "EqualsCommand.h"
#include "ShuntingYard.h"
#include <unistd.h>
#include <iostream>

EqualsCommand::EqualsCommand(GlobalData *data) {
    m_data = data;
}

int EqualsCommand::execute(vector<string> script, unsigned long index) {
    ShuntingYard shunt(m_data);
    string variable = script[index]; // store the variable name in a local string variable
    vector<string> line; // vector to copy the line for future manipulation
    unsigned long temp_index = index;
    int counter = 0;
    while (script[temp_index] != "\n") { // copy the line of the equals expression
        line.push_back(script[temp_index]);
        temp_index++;
        counter++;
    }
    // check if the variable assignment is to another variable
    if (variableExists(script[index + 2]) && script[index + 3] == "\n") {
        m_data->addToSymbolTable(variable, m_data->getSymbolTable().find(line[index + 2])->second);
    } else { // variable assignment is to an Expression
        line.erase(line.begin()); // remove the variable name from vector
        line.erase(line.begin()); // remove "=" from vector
        m_data->addToSymbolTable(variable, shunt.evaluateExpression(line)->calculate());
    }
    if (addressExists(variable)) { // check if the variable has an address attached
        update(variable);
    }
    return ++counter;
}

bool EqualsCommand::variableExists(string variable) {
    return m_data->isExists(variable);
}

bool EqualsCommand::addressExists(string &variable) {
    return m_data->isBind(variable);
}

void EqualsCommand::update(string variable) {
    int n;
    string msg = "set " + m_data->getAddressTable().find(variable)->second;
    msg += " " + to_string(m_data->getSymbolTable().find(variable)->second) + "\r\n";

    int sockfd = m_data->getClientSock();

    //   Send message to the server to update the variable value
    n = write(sockfd, msg.c_str(), msg.length());

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}