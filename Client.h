#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

#include <string>

using namespace std;

class Client {
const char *m_server_IP;
int m_server_port;
int m_client_socket;
public:
    Client(const char *server_IP, int server_port);
    void connectToServer();
};


#endif //PROJECT_CLIENT_H
