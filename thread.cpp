#include "thread.h"

Thread::Thread(int saved_sock,QObject *parent) :
    QThread(parent)
{
    sock = saved_sock;
}
void Thread::run()
{
    char msg[1024];
    while(recv(sock, msg, sizeof(msg),0) != -1)
    {
        QString recv_msg = QString::fromStdString(msg);
        if(recv_msg.length()>=1)
            emit Send(recv_msg);
        memset(msg,0,sizeof(msg));
    }
}
