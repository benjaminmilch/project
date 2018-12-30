//
// Created by adiel on 25/12/18.
//
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include "GlobalData.h"
#include <sys/socket.h>
#include <thread>
#include "DataReaderServer.h"

using namespace std;

/****************************************************************
* Function Name: getMessage                                     *
* Parameters: Two ints and pointer to GlobalData                *
* Functionality: This function gets a message by the thread to  *
*   allow functionality in the background.                      *
****************************************************************/
void getMessage(int freq, int newsockfd, GlobalData *globalData)
{
    int n;
    char buffer[256];
    while (true) {
        /* If connection is established then start communicating */
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
        globalData->setBuffer(buffer);
        globalData->update();
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        this_thread::sleep_for(chrono::seconds(1 / freq));
        if (globalData->isHalt()) {
            globalData->setHalt(false);
        }
    }
}
DataReaderServer::DataReaderServer(GlobalData *gd)
{
    m_globalData = gd;
}
void DataReaderServer::runServer(int port, int freq)
{
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    m_globalData->setServer_sock((sockfd));
    if (sockfd == -1) {
        throw "ERROR opening socket";
    }

    bzero((void *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        throw "ERROR on binding";
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    thread t(getMessage, freq, newsockfd, m_globalData);
    t.detach();
}