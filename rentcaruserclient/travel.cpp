#include "travel.h"
#include "ui_travel.h"

travel::travel(QString id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::travel)
{
    userid = id;
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,250);
    ui->tableWidget->setColumnWidth(1,250);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

travel::~travel()
{
    delete ui;
}

void travel::on_exit_clicked()
{
    this->close(); // 기존 창 닫기
    menu menu(userid); // 객체 생성
    menu.setModal(true); // 정보찾기창 열기
    menu.exec(); // 정보찾기창 닫으면
    this->show();
}

void travel::on_search_clicked()
{
    QSqlQuery query;
    QSqlRecord rec;
    QString SQL, keyword;
    keyword = ui->lineEdit->text(); // lineedit에 입력한 것을 keyword라는 변수에 저장
    ui->tableWidget->setRowCount(0);
    if(ui->comboBox->currentText() == "관광지명")
        SQL="SELECT * FROM travel where name LIKE '%"+keyword+"%'";
    else if(ui->comboBox->currentText() == "주소")
                SQL="SELECT * FROM travel where addr LIKE '%"+keyword+"%'";
    else
                SQL="SELECT * FROM travel where name LIKE '%"+keyword+"%' or addr LIKE '%"+keyword+"%' or beach LIKE '%"+keyword+"%'";
    query.exec(SQL);
    while(query.next())
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
    }
}
