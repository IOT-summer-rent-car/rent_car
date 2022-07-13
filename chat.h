#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include <QMessageBox>
#include <QtNetwork>
#include <cstring>
#include <string>

#include "thread.h"
#include "Con_server.h"
#include "con_DB_rent_car.h"

namespace Ui {
class Chat;
}

class Chat : public QDialog,public con_server
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();

private slots:
    void Receive(QString recv_msg);

    void on_send_btn_clicked();

    void closeEvent(QCloseEvent *);

private:
    std::string query_string;
    QSqlQuery query;
    QString start_chat_date;
    Thread *thread;
    Ui::Chat *ui;
};

#endif // CHAT_H
