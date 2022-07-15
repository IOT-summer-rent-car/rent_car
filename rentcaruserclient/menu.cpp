#include "menu.h"
#include "ui_menu.h"
#include "carsearch.h"
#include "reserv.h"
#include "travel.h"
#include "talk.h"

menu::menu(QString id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    userid = id;
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked() // 조회
{
    this->close(); // 기존 창 닫기
    carsearch userWindow(userid); // 객체 생성
    userWindow.setModal(true); // 창 열기
    userWindow.exec(); // 창 닫으면
    this->show(); // 기존에 열렸던 창 다시 열기
}

void menu::on_pushButton_2_clicked() // 예약확인
{
    this->close(); // 기존 창 닫기
    reserv userWindow(userid); // 객체 생성
    userWindow.setModal(true); // 창 열기
    userWindow.exec(); // 창 닫으면
    this->show(); // 기존에 열렸던 창 다시 열기
}

void menu::on_pushButton_3_clicked() // 여행지정보
{
    this->close(); // 기존 창 닫기
    travel userWindow(userid); // 객체 생성
    userWindow.setModal(true); // 창 열기
    userWindow.exec(); // 창 닫으면
    this->show(); // 기존에 열렸던 창 다시 열기
}

void menu::on_pushButton_4_clicked() // 회원탈퇴
{
    QSqlQuery query;
    QString SQL;
    SQL="select count(*) from reserv where id = '"+userid+"'"; // 예약확인
    qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
    query.exec(SQL);
    query.next(); // 쿼리문 실행결과 확인
    if(query.value(0).toString() == '0') // 예약한 것이 없다면
    {
        SQL="select user from user where id = '"+userid+"'"; // 이름 추출
        qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
        query.exec(SQL);
        query.next(); // 쿼리문 실행결과 확인
        QString username = query.value(0).toString();
        SQL="delete from user where id = '"+userid+"'"; // 탈퇴
        qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
        query.exec(SQL);
        QMessageBox::information(nullptr,"탈퇴 성공","나가.");
        this->close();
    }
    else
        QMessageBox::information(nullptr,"탈퇴 실패","예약상태에서는 할수 없습니다.");
}

void menu::on_pushButton_5_clicked() // 상담
{
    this->close(); // 기존 창 닫기
    talk userWindow(userid); // 객체 생성
    userWindow.setModal(true); // 창 열기
    userWindow.exec(); // 창 닫으면
    this->show(); // 기존에 열렸던 창 다시 열기
}
