#include "mainwindow.h"
#include <QMessageBox>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <QApplication>
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
