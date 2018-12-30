#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

#include <string>
#include "GlobalData.h"

using namespace std;

/****************************************************************
* Class Name: Client                                            *
* Constructor: Const char, int, and pointer to GlobalData       *
* Class Functionality: This class is used for the client        *
*   connection to a socket with the IP address.                 *
****************************************************************/
class Client {
    // members
    const char *m_server_IP;
    int m_server_port;
    GlobalData* m_globalData;
public:
    Client(const char *server_IP, int server_port, GlobalData *globalData); // constructor
    void connectToServer(); // connects the client socket to the server
};


#endif //PROJECT_CLIENT_H
