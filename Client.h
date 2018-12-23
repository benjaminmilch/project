#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H


class Client {
const char *m_server_IP;
int m_server_port;
int m_client_socket;
public:
    Client(const char *server_IP, int server_port);
    void connectToServer();
    int sendUpdates(int argc, char *argv[]);
};


#endif //PROJECT_CLIENT_H
