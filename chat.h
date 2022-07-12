#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include <QMessageBox>
#include <QtNetwork>
#include <thread>

#include "Con_server.h"

namespace Ui {
class Chat;
}

class Chat : public QDialog
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();

private slots:
    void recv_thread();

    void call_thread();

    void on_send_btn_clicked();

    void closeEvent(QCloseEvent *);

private:
    int sock;
    con_server c;
    Ui::Chat *ui;
};

#endif // CHAT_H
