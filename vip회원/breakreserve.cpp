#include "breakreserve.h"
#include "ui_breakreserve.h"
#include "menu.h"

breakreserve::breakreserve(QString id, QString beachname, QString facility, QString guidename, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::breakreserve)
{
    userid = id;
    userbeach = beachname;
    userfacility = facility;
    userguide = guidename;
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,109);
    ui->tableWidget->setColumnWidth(1,109);
    ui->tableWidget->setColumnWidth(2,109);
    ui->tableWidget->setColumnWidth(3,109);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QSqlQuery query;
    QSqlRecord rec;
    QString SQL;
    ui->tableWidget->setRowCount(0);
    SQL="SELECT beach, facility, guideName, date FROM reservationTB where userId = '"+userid+"'";
    query.exec(SQL);
    while(query.next())
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(query.value(3).toString()));
    }
}

breakreserve::~breakreserve()
{
    delete ui;
}

void breakreserve::on_exit_clicked() // 돌아가기 버튼 클릭
{
    this->hide(); // 기존 창 닫기
    menu menu(userid); // 객체 생성
    menu.setModal(true); // 정보찾기창 열기
    menu.exec(); // 정보찾기창 닫으면
    this->show();
}

void breakreserve::on_tableWidget_cellDoubleClicked() // 테이블 더블클릭
{
    userbeach = ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text();
    userfacility = ui->tableWidget->item(ui->tableWidget->currentRow(), 1)->text();
    userguide = ui->tableWidget->item(ui->tableWidget->currentRow(), 2)->text();
    date = ui->tableWidget->item(ui->tableWidget->currentRow(), 3)->text();
    qDebug()<<userguide<<endl<<userfacility<<endl;
}

void breakreserve::on_breakbt_clicked() // 예약취소 버튼 클릭
{
    QSqlQuery query;
    QString SQL;
    //ui->tableWidget->setRowCount(0);
    SQL="update facilityTB set roomCount = roomCount+1 where facility = '"+userfacility+"'"; // 숙소 수정
    qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
    query.exec(SQL);
    SQL="update guideTB set guideOK = guideOK+1 where guideName = '"+userguide+"'"; // 가이드 수정
    qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
    query.exec(SQL);
    SQL="insert into delreservationTB values('"+userid+"', '"+userbeach+"', '"+userfacility+"', '"+userguide+"', '"+date+"')"; // 삭제리스트에 추가
    qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
    query.exec(SQL);
    SQL="delete from reservationTB where userid = '"+userid+"' and beach = '"+userbeach+"' and facility = '"+userfacility+"' and guideName = '"+userguide+"' and date = '"+date+"'"; // 삭제
    qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
    query.exec(SQL);
    QMessageBox::information(nullptr,"성공","예약 취소 완료.");
    ui->tableWidget->setRowCount(0);
    SQL="SELECT beach, facility, guideName, date FROM reservationTB where userId = '"+userid+"'";
    query.exec(SQL);
    while(query.next())
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(query.value(3).toString()));
    }
}
