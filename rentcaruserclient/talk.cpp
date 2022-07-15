#include "talk.h"
#include "ui_talk.h"
#include <string>

talk::talk(QString id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::talk)
{
    userid = id;
    QString SQL;
    char msg[1024];
    QSqlQuery query;
    SQL="select name from user where id = '"+userid+"'"; // 이름찾기
    qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
    query.exec(SQL);  // 쿼리문 실행
    query.next();
    username = query.value(0).toString();
    write(sock, "클라", sizeof("클라")); // 클라이언트가 접속했다고 알려줌
    read(sock, msg, sizeof(msg)); // 꺼짐
    //recv(sock, msg, sizeof(msg), 0); // 꺼짐
    std::cout<<msg<<std::endl;
    if(strcmp("NO",msg)==0) // NO를 받으면.
    {
        this->close(); // 기존 창 닫기
        menu menu(userid); // 객체 생성라
        menu.setModal(true); // 정보찾기창 열기
        menu.exec(); // 정보찾기창 닫으면
        this->show();
    }
    else // 아니면
    {
        ui->setupUi(this);
        start_chat_date = QDateTime::currentDateTime().toString();
        std::cout<<msg<<std::endl;
        ui->textEdit->setEnabled(false);
        ui->textEdit->setTextColor(QColor("black"));
        thread = new Thread(sock);
        connect(thread, SIGNAL(Send(char*)), this, SLOT(Receive(char*)));
        thread->start();
    }
}

talk::~talk()
{
    delete ui;
}

void talk::on_lineEdit_returnPressed()
{
    std::string send_data = "[" + username.toStdString() + "] " + ui->lineEdit->text().toStdString() + "";
    send(sock, send_data.c_str(), send_data.size(), 0);
    ui->lineEdit->clear();
}
void talk::Receive(char* data)
{
    qDebug() << data;
    ui->textEdit->append(data);
}

void talk::on_exit_clicked()
{
    this->close(); // 기존 창 닫기
    menu menu(userid); // 객체 생성
    menu.setModal(true); // 정보찾기창 열기
    menu.exec(); // 정보찾기창 닫으면
    this->show();
}

void talk::closeEvent(QCloseEvent *)
{
    thread->terminate();
    QSqlQuery query;
    shutdown(sock,SHUT_RDWR);
    QString now = start_chat_date +" ~ "+QDateTime::currentDateTime().toString();
    QString text = ui->textEdit->toPlainText();

    if(text != "")
    {
        query.prepare("INSERT INTO chat_log(date,log) "
                      "VALUES (?, ?)");

        query.addBindValue(now);
        query.addBindValue(text);

        query.exec();
    }
}
