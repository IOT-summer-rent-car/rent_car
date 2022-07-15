#include "carsearch.h"
#include "ui_carsearch.h"
#include "carrent.h"

carsearch::carsearch(QString id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::carsearch)
{
    userid = id;
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,100);
    ui->tableWidget->setColumnWidth(1,100);
    ui->tableWidget->setColumnWidth(2,100);
    ui->tableWidget->setColumnWidth(3,100);
    ui->tableWidget->setColumnWidth(4,100);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

carsearch::~carsearch()
{
    delete ui;
}

void carsearch::on_tableWidget_cellDoubleClicked()
{
    carname = ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text();
    qDebug()<<carname<<endl;
    ui->label_2->setText(carname);
}

void carsearch::on_exit_clicked()
{
    this->close(); // 기존 창 닫기
    menu menu(userid); // 객체 생성
    menu.setModal(true); // 정보찾기창 열기
    menu.exec(); // 정보찾기창 닫으면
    this->show();
}

void carsearch::on_search_clicked()
{
    QSqlQuery query;
    QSqlRecord rec;
    QString SQL, keyword;
    keyword = ui->lineEdit->text(); // lineedit에 입력한 것을 keyword라는 변수에 저장
    ui->tableWidget->setRowCount(0);
    if(ui->comboBox->currentText() == "차량이름")
        SQL="SELECT * FROM cars where name LIKE '%"+keyword+"%'";
    else if(ui->comboBox->currentText() == "유종")
                SQL="SELECT * FROM cars where kind LIKE '%"+keyword+"%'";
    else if(ui->comboBox->currentText() == "특징")
                SQL="SELECT * FROM cars where data LIKE '%"+keyword+"%'";
    else
                SQL="SELECT * FROM cars where name LIKE '%"+keyword+"%' or kind LIKE '%"+keyword+"%' or data LIKE '%"+keyword+"%'";
    query.exec(SQL);
    while(query.next())
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem(query.value(4).toString()));
    }
}

void carsearch::on_reserv_clicked()
{
    this->close(); // 기존 창 닫기
    carrent carrent(userid, carname); // 객체 생성
    carrent.setModal(true); // 정보찾기창 열기
    carrent.exec(); // 정보찾기창 닫으면
    this->show();
}
