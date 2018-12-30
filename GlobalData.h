//
// Created by adiel on 25/12/18.
//

#ifndef PROJECT_GLOBALDATA_H
#define PROJECT_GLOBALDATA_H


#include <vector>
#include "AddressSpot.h"
#include "Command.h"

/****************************************************************
* Class Name: GlobalData                                        *
* Constructor: Default Constructor                              *
* Class Functionality: This class is the "global data" of the   *
*   program, storing as its members the data other classes use  *
*   throughout the program. The purpose of this class is to     *
*   centralize the data access.                                 *
****************************************************************/
class GlobalData {
    // members
    volatile bool m_halt; // stopping condition
    int m_server_sock;
    int m_client_sock;
    map<string, double> m_symbol_table; // variable name with its double value
    map<string, string> m_address_table; //variable name with its address
    vector<double> m_buffer;
    AddressSpot m_address_spot = AddressSpot();
public:
    bool isHalt() const; // return if thread needs to stop or not
    void setHalt(bool holt);

    // getter and setter for client socket, setter for server socket
    int getClientSock() const;
    void setClientSock(int sockfd);
    void setServer_sock(int server_sock);

    // getter and setter for buffer used for the sockets sending/receiving messages
    const vector<double> &getBuffer() const;
    void setBuffer(const string &buffer);

    // getter for variable tables and add methods to add to these tables
    const map<string, double> &getSymbolTable() const;
    const map<string, string> &getAddressTable() const;
    void addToSymbolTable(string var, double val);
    void addToAddressTable(string var, string addr);

    // checks existence of variable in a variable table
    bool isBind(string var);
    bool isExists(string var);

    // returns a map class of all the addresses in the XML with its corresponding location index
    AddressSpot &getAddressSpot();

    // update symbol table by the sockets (from Flight Gear)
    void update();

    // closes both server and client sockets on the programs end
    void closeSockets();
};


#endif //PROJECT_GLOBALDATA_H
