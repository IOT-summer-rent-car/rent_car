#include "menu.h"
#include "ui_menu.h"
#include "beach.h"
#include "facility.h"
#include "guide.h"
#include "reservation.h"
#include "breakreserve.h"

menu::menu(QString id, QString beachname, QString facility, QString guidename, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    userid = id;
    userbeach = beachname;
    userfacility = facility;
    userguide = guidename;
    ui->setupUi(this);
    QSqlQuery query; // 쿼리문을 실행하기 위한 변수
    QString SQL; // 쿼리문을 넣기 위한 QString 변수 선언
    SQL="select userName FROM userTB WHERE userId = '"+id+"'"; // 쿼리문
    qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
    query.exec(SQL);  // 쿼리문 실행
    query.next(); // 쿼리문 실행결과 확인
    ui->label->setText(query.value(0).toString());
    ui->beachlabel->setText(userbeach);
    ui->facilitylabel->setText(userfacility);
    ui->guidelabel->setText(userguide);
}
menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked() // 관광지 버튼 클릭했을 경우
{
    qDebug()<<"관광지 검색"<<endl; // 함수 진입확인용 출력문
    this->hide(); // 기존 창 닫기
    beach userWindow(userid, userbeach, userfacility, userguide); // 객체 생성
    userWindow.setModal(true); // 창 열기
    userWindow.exec(); // 창 닫으면
    this->show();
}

void menu::on_pushButton_2_clicked() // 숙소 버튼 클릭했을 경우
{
    qDebug()<<"숙소 검색"<<endl; // 함수 진입확인용 출력문
    this->hide(); // 기존 창 닫기
    facility userWindow(userid, userbeach, userfacility, userguide); // 객체 생성
    userWindow.setModal(true); // 창 열기
    userWindow.exec(); // 창 닫으면
    this->show();
}

void menu::on_pushButton_3_clicked() // 가이드 버튼 클릭했을 경우
{
    qDebug()<<"가이드 검색"<<endl; // 함수 진입확인용 출력문
    this->hide(); // 기존 창 닫기
    Guide userWindow(userid, userbeach, userfacility, userguide); // 객체 생성
    userWindow.setModal(true); // 창 열기
    userWindow.exec(); // 창 닫으면
    this->show();
}

void menu::on_pushButton_4_clicked() // 예약하기 버튼 클릭했을 경우
{
    if(userid != NULL && userbeach != NULL && userfacility != NULL && userguide != NULL)
    {
        this->hide(); // 기존 창 닫기
        reservation userWindow(userid, userbeach, userfacility, userguide); // 객체 생성
        userWindow.setModal(true); // 창 열기
        userWindow.exec(); // 창 닫으면
        this->show();
    }
}

void menu::on_pushButton_5_clicked() // 예약취소
{
    qDebug()<<"가이드 검색"<<endl; // 함수 진입확인용 출력문
    this->hide(); // 기존 창 닫기
    breakreserve userWindow(userid, userbeach, userfacility, userguide); // 객체 생성
    userWindow.setModal(true); // 창 열기
    userWindow.exec(); // 창 닫으면
    this->show();
}

void menu::on_pushButton_6_clicked() // 회원탈퇴
{
    QSqlQuery query;
    QString SQL;
    SQL="select count(*) from reservationTB where userId = '"+userid+"'"; // 예약확인
    qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
    query.exec(SQL);
    query.next(); // 쿼리문 실행결과 확인
    if(query.value(0).toString() == '0') // 예약한 것이 없다면
    {
        SQL="select userName from userTB where userid = '"+userid+"'"; // 이름 추출
        qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
        query.exec(SQL);
        query.next(); // 쿼리문 실행결과 확인
        QString username = query.value(0).toString();
        SQL="delete from userTB where userId = '"+userid+"'"; // 탈퇴
        qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
        query.exec(SQL);
        SQL="insert into deluserTB values('"+userid+"', '"+username+"')"; // 예약확인
        qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
        query.exec(SQL);
        QMessageBox::information(nullptr,"탈퇴 성공","나가.");
        this->close();
    }
}
