#include "reserv.h"
#include "ui_reserv.h"

reserv::reserv(QString id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reserv)
{
    userid = id;
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,250);
    ui->tableWidget->setColumnWidth(1,250);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QSqlQuery query;
    QSqlRecord rec;
    QString SQL;
    ui->tableWidget->setRowCount(0);
    SQL="SELECT car_name, date FROM reserv where id = '"+userid+"'";
    query.exec(SQL);
    while(query.next())
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
    }
}

reserv::~reserv()
{
    delete ui;
}

void reserv::on_tableWidget_cellDoubleClicked()
{
    car_name = ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text();
    qDebug()<<car_name<<endl;
    ui->label_2->setText(car_name);
}

void reserv::on_pushButton_clicked()
{
    QSqlQuery query;
    QString SQL;
    //ui->tableWidget->setRowCount(0);
    SQL="update cars set rent = 'O' where car_name = '"+car_name+"'"; // 대여상태 수정
    qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
    query.exec(SQL);
    SQL="delete from reserv where id = '"+userid+"' and car_name = '"+car_name+"'"; // 삭제
    qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
    query.exec(SQL);
    QMessageBox::information(nullptr,"성공","예약 취소 완료.");
    ui->tableWidget->setRowCount(0);
    SQL="SELECT car_name, date FROM reserv where id = '"+userid+"'";
    query.exec(SQL);
    while(query.next())
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
    }
}

void reserv::on_exit_clicked()
{
    this->close(); // 기존 창 닫기
    menu menu(userid); // 객체 생성
    menu.setModal(true); // 정보찾기창 열기
    menu.exec(); // 정보찾기창 닫으면
    this->show();
}
