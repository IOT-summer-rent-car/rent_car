#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);

    sock = c.sock;
    qDebug()<<sock;

    call_thread();
}

void Chat::call_thread()
{
    std::thread recv = std::thread([&]{recv_thread();});
    recv.join();
}

Chat::~Chat()
{
    delete ui;
}

void Chat::recv_thread()
{
    qDebug()<<"ㅎㅇ";
    char msg[BUF_SIZE];
    while(1)
    {

        std::cout<<msg<<std::endl;
        QString recv_msg = QString::fromStdString(msg);
        if(recv_msg.length() >=1)
        {
            ui->list->append(recv_msg);
        }
    }
    qDebug()<<"ㅎㅇ";
};

void Chat::on_send_btn_clicked()
{
    std::string send_msg = ui->chat->text().toStdString();
    write(sock, send_msg.c_str(), sizeof(send_msg));
    ui->chat->clear();
}

void Chat::closeEvent(QCloseEvent *)
{

}
