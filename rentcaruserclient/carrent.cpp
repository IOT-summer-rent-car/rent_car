#include "carrent.h"
#include "ui_carrent.h"
#include "menu.h"

carrent::carrent(QString id, QString car_name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::carrent)
{
    userid = id;
    carname = car_name;
    ui->setupUi(this);
}

carrent::~carrent()
{
    delete ui;
}

void carrent::on_calendarWidget_clicked()
{
    QString day, month;
    QString date = ui->calendarWidget->selectedDate().toString("yyyy.MM.dd");
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
        QString SQL, username; // 쿼리문을 넣기 위한 QString 변수 선언
        QSqlQuery query;
        SQL="select count(*) from reserv where car_name = '"+carname+"'"; // 대여현황 체크
        qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
        query.exec(SQL);  // 쿼리문 실행
        query.next();
        if(query.value(0).toString() != '0') // 대여상태일 경우
        {
            QMessageBox::critical(nullptr,"예약 불가","대여상태");
        }
        else
        {
            SQL="update cars set rent = 'O' where name = '"+carname+"'"; // 대여상태로 바꿈
            qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
            query.exec(SQL);  // 쿼리문 실행
            SQL="select name from user where id = '"+userid+"'"; // 이름찾기
            qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
            query.exec(SQL);  // 쿼리문 실행
            query.next();
            username = query.value(0).toString();
            SQL="insert into reserv values('"+userid+"', '"+username+"', '"+carname+"', '"+date+"')"; // 예약리스트에 추가
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

    this->close(); // 기존 창 닫기
    menu menu(userid); // 객체 생성
    menu.setModal(true); // 정보찾기창 열기
    menu.exec(); // 정보찾기창 닫으면
    this->show();
}

void carrent::on_exit_clicked()
{
    this->close(); // 기존 창 닫기
    menu menu(userid); // 객체 생성
    menu.setModal(true); // 정보찾기창 열기
    menu.exec(); // 정보찾기창 닫으면
    this->show();
}
