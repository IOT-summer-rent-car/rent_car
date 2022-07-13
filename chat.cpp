#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    start_chat_date = QDateTime::currentDateTime().toString();
    thread = new Thread(sock);
    thread->start();
    std::string ser = "서버";

    write(sock, (void *)ser.c_str(), sizeof(ser));

    connect(thread, SIGNAL(Send(QString)), this, SLOT(Receive(QString)));
}
Chat::~Chat()
{
    delete ui;
}

void Chat::Receive(QString recv_msg)
{
    ui->list->append(recv_msg);
}

void Chat::on_send_btn_clicked()
{
    std::string send_msg = ui->chat->text().toStdString();
    send_msg = "[서버] "+send_msg;
    send(sock, (void *)send_msg.c_str(), send_msg.size(),0);
    ui->chat->clear();
}

void Chat::closeEvent(QCloseEvent *)
{
    shutdown(sock,SHUT_RDWR);
    QString now = start_chat_date +" ~ "+QDateTime::currentDateTime().toString();
    QString text = ui->list->toPlainText();

    if(text != "")
    {
        query.prepare("INSERT INTO chat_log(date,log) "
                      "VALUES (?, ?)");

        query.addBindValue(now);
        query.addBindValue(text);

        query.exec();
    }
}
