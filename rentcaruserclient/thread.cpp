#include "thread.h"
#include <unistd.h>
#include <sys/socket.h>
#include <iostream>
#include <string>

Thread::Thread(int saved_sock,QObject *parent) :
    QThread(parent)
{
    sock = saved_sock;
}
void Thread::run()
{
    char msg[1024];
    while(recv(sock, msg, 1024, 0) != -1)
    {
        if(sizeof(msg) != 0)
        {
            std::cout<<msg<<std::endl;
            emit Send(msg);
        }

    }
}
