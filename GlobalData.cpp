//
// Created by adiel on 25/12/18.
//

#include <unistd.h>
#include "GlobalData.h"
#include "Lexer.h"

bool GlobalData::isHalt() const
{
    return m_halt;
}
void GlobalData::setHalt(bool halt)
{
    GlobalData::m_halt = halt;
}

int GlobalData::getClientSock() const
{
    return m_client_sock;
}
void GlobalData::setClientSock(int sockfd)
{
    m_client_sock = sockfd;
}
void GlobalData::setBuffer(const string &buffer)
{
    Lexer l;
    vector<string> temp = l.splitter(buffer, ',');
    m_buffer.clear();
    for (auto& i : temp) {
        m_buffer.push_back(stod(i));
    }
}
const vector<double> &GlobalData::getBuffer() const
{
    return m_buffer;
}
AddressSpot &GlobalData::getAddressSpot()
{
    return m_address_spot;
}
const map<string, double> &GlobalData::getSymbolTable() const
{
    return m_symbol_table;
}
void GlobalData::addToSymbolTable(string var, double val)
{
    if (!isExists(var)) {
        m_symbol_table.insert({var, val});
    } else {
        m_symbol_table[var] = val;
    }
}
const map<string, string> &GlobalData::getAddressTable() const
{
    return m_address_table;
}
void GlobalData::addToAddressTable(string var, string addr)
{
    m_address_table.insert({var, addr});
}
bool GlobalData::isBind(string var)
{
    return m_address_table.find(var) != m_address_table.end();
}
bool GlobalData::isExists(string var)
{
    return m_symbol_table.find(var) != m_symbol_table.end();
}
void GlobalData::update()
{
    map<string, double>::iterator i;
    for (i = m_symbol_table.begin(); i != m_symbol_table.end(); i++) {
        if (isBind(i->first)) {
            string addr = m_address_table[i->first];
            int newValSpot = getAddressSpot().getSpot(addr);
            i->second = getBuffer()[newValSpot];
        }
    }

}
void GlobalData::setServer_sock(int server_sock)
{
    GlobalData::m_server_sock = server_sock;
}
void GlobalData::closeSockets()
{
    close(m_client_sock);
    close(m_server_sock);
}
