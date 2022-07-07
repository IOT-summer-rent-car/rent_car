#include "facility.h"
#include "ui_facility.h"
#include "menu.h"

facility::facility(QString id, QString beachname, QString facility, QString guidename, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::facility)
{
    userid = id;
    userbeach = beachname;
    userfacility = facility;
    userguide = guidename;
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,218);
    ui->tableWidget->setColumnWidth(1,218);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

facility::~facility()
{
    delete ui;
}

void facility::on_lineEdit_returnPressed() // enter
{
    QSqlQuery query;
    QSqlRecord rec;
    QString SQL, keyword;
    ui->tableWidget->setRowCount(0);
    keyword = ui->lineEdit->text(); // lineedit에 입력한 것을 keyword라는 변수에 저장
    SQL="SELECT * FROM facilityTB where facility LIKE '%"+keyword+"%'";
    query.exec(SQL);
    rec=query.record();
    while(query.next())
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
    }
}


void facility::on_pushButton_clicked() // 검색 버튼
{
    on_lineEdit_returnPressed();
}

void facility::on_exit_clicked() // 돌아가기 버튼
{
    this->hide(); // 기존 창 닫기
    menu menu(userid, userbeach, userfacility, userguide); // 객체 생성
    menu.setModal(true); // 정보찾기창 열기
    menu.exec(); // 정보찾기창 닫으면
    this->show();
}

void facility::on_tableWidget_cellDoubleClicked() // 선택했을 경우
{
    userfacility = ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text();
    qDebug()<<userfacility<<endl;
    ui->label_2->setText(userfacility);
}
