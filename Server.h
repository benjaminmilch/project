//
// Created by adiel on 23/12/18.
//

#ifndef PROJECT_SERVER_H
#define PROJECT_SERVER_H


class Server {
    int port;
    int sockfd;
public:
    Server(int port);
    void start();
    void stop();
};


#endif //PROJECT_SERVER_H
