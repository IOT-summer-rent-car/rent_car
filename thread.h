#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QtDebug>
#include <QtNetwork>
#include <iostream>

#include "Con_server.h"

class Thread : public QThread
{
    Q_OBJECT

public:
    explicit Thread(int saved_sock,QObject *parent = 0);

private:
    int sock;
    void run();
signals:
    void Send(QString recv_msg);
};

#endif // THREAD_H
