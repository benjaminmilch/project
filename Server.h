#ifndef PROJECT_SERVER_H
#define PROJECT_SERVER_H

class Server {
    double port;
    int sockfd;
public:
    Server(double port);
    void start();
};

#endif //PROJECT_SERVER_H