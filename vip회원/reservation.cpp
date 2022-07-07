#include "reservation.h"
#include "ui_reservation.h"
#include "menu.h"
#include <cstring>
#include <cstdio>
using namespace std;

reservation::reservation(QString id, QString beachname, QString facility, QString guidename, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservation)
{
    userid = id;
    userbeach = beachname;
    userfacility = facility;
    userguide = guidename;
    ui->setupUi(this);
}

reservation::~reservation()
{
    delete ui;
}

void reservation::on_calendarWidget_clicked()
{
    QString day, month;
    QString date = ui->calendarWidget->selectedDate().toString("MM/dd");
    QMessageBox msgBox;
    msgBox.setText(date);
    msgBox.setInformativeText("예약하시겠습니까?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::No | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int result = msgBox.exec();
    switch (result)
    {
    case QMessageBox::Ok:
    {
        int count = 0; // 예약이 불가능할 경우를 위한 카운트
        qDebug()<<"Ok"<<endl;
        QString SQL; // 쿼리문을 넣기 위한 QString 변수 선언
        QSqlQuery query;
        SQL="select count(*) from facilityTB where facility = '"+userfacility+"'"; // 숙소인원 체크
        qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
        query.exec(SQL);  // 쿼리문 실행
        if(query.value(0).toString() == '0') // 숙소 남은방이 0일 경우
        {
            QMessageBox::critical(nullptr,"예약 불가","숙소인원 부족");
            qDebug()<<"숙소 인원 부족"<<endl;
            count++;
        }
        SQL="select count(*) from guideTB where guideName = '"+userguide+"'"; // 가이드카운트 체크
        qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
        query.exec(SQL);  // 쿼리문 실행
        if(query.value(0).toString() == '0') // 가이드가 부재중일 경우
        {
            QMessageBox::critical(nullptr,"예약 불가","가이드 부재중");
            qDebug()<<"가이드 부재중"<<endl;
            count++;
        }
        if(count == 0)
        {
            SQL="update facilityTB set roomCount = roomCount-1 where facility = '"+userfacility+"'"; // 숙소인원 감소
            qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
            query.exec(SQL);  // 쿼리문 실행
            SQL="update guideTB set guideOK = guideOK-1 where guideName = '"+userguide+"'"; // 가이드카운트 감소
            qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
            query.exec(SQL);  // 쿼리문 실행
            SQL="insert into reservationTB values('"+userid+"', '"+userbeach+"', '"+userfacility+"', '"+userguide+"', '"+date+"')"; // 예약리스트에 추가
            qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
            query.exec(SQL);  // 쿼리문 실행
            qDebug()<<"예약 완료"<<endl;
            QMessageBox::information(nullptr,"예약 성공","예약이 완료되었습니다.");
            this->close();
        }
        break;
    }
    case QMessageBox::No:
        qDebug()<<"No"<<endl;
        break;
    case QMessageBox::Cancel:
        qDebug()<<"취소"<<endl;
        break;
    default:
        break;
    }
}
