#include "Client.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

Client::Client(const char *server_IP, int server_port)
{
    m_server_IP = server_IP;
    m_server_port = server_port;
}
void Client::connectToServer()
{
    struct sockaddr_in serv_addr;
    struct hostent *server;

    m_client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_client_socket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(m_server_IP);

    if (server == nullptr) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(m_server_port);

    /* Now connect to the server */
    if (connect(m_client_socket, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
}
int Client::sendUpdates(string var, double value)
{
    char buffer[256];
    int n;
    /* Now ask for a message from the user, this message
       * will be read by server
    */

    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    /* Send message to the server */
    n = write(m_client_socket, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Now read server response */
    bzero(buffer,256);
    n = read(m_client_socket, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n",buffer);
    return 0;
}

