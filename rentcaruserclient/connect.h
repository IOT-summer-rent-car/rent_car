#ifndef CONNECT_H
#define CONNECT_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <QDebug>
#include <iostream>
#include <unistd.h>


class Connect
{
public:
    int sock;
    Connect(){
        struct sockaddr_in serv_addr;

        sock = socket(AF_INET, SOCK_STREAM, 0);
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr("10.10.20.232");
        serv_addr.sin_port = htons(atoi("9036"));

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
            qDebug()<<"con_error";
    }
    ~Connect()
    {}
};

#endif // CONNECT_H
