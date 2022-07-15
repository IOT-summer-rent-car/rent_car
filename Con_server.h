#ifndef CON_SERVER_H
#define CON_SERVER_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <unistd.h>

#define BUF_SIZE 1024

class con_server
{
public:
    int sock;
    con_server(){
        struct sockaddr_in serv_addr;

        sock = socket(AF_INET, SOCK_STREAM, 0);
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr("10.10.20.232");
        serv_addr.sin_port = htons(atoi("9030"));
    }
    ~con_server(){}
};

#endif // CON_SERVER_H
