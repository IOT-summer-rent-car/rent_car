#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QtDebug>

class Thread : public QThread
{
    Q_OBJECT
    int sock;

public:
    explicit Thread(int saved_sock,QObject *parent = 0);

private:
    void run();

signals:
    void Send(char* data);
};

#endif // THREAD_H
