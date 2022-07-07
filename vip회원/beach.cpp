#include "beach.h"
#include "ui_beach.h"
#include "menu.h"

beach::beach(QString id, QString beachname, QString facility, QString guidename, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::beach)
{
    userid = id;
    userbeach = beachname;
    userfacility = facility;
    userguide = guidename;
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,218);
    ui->tableWidget->setColumnWidth(1,218);
    ui->tableWidget->setColumnWidth(2,218);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

beach::~beach()
{
    delete ui;
}

void beach::on_lineEdit_returnPressed() // enter로 검색 시도할 경우
{
    QSqlQuery query;
    QSqlRecord rec;
    QString SQL, keyword;
    keyword = ui->lineEdit->text(); // lineedit에 입력한 것을 keyword라는 변수에 저장
    ui->tableWidget->setRowCount(0);
    if(ui->comboBox->currentText() == "지역명")
        SQL="SELECT * FROM beachTB where local LIKE '%"+keyword+"%'";
    else if(ui->comboBox->currentText() == "도시명")
                SQL="SELECT * FROM beachTB where office LIKE '%"+keyword+"%'";
    else if(ui->comboBox->currentText() == "해변명")
                SQL="SELECT * FROM beachTB where beach LIKE '%"+keyword+"%'";
    else
                SQL="SELECT * FROM beachTB where local LIKE '%"+keyword+"%' or office LIKE '%"+keyword+"%' or beach LIKE '%"+keyword+"%'";
    query.exec(SQL);
    while(query.next())
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(query.value(2).toString()));
    }
}

void beach::on_pushButton_clicked() // 검색 버튼을 눌렀을 경우
{
    on_lineEdit_returnPressed();
}

void beach::on_tableWidget_cellDoubleClicked() // 클릭했을 때 해당하는 해변명 반환
{
    userbeach = ui->tableWidget->item(ui->tableWidget->currentRow(), 2)->text();
    qDebug()<<userbeach<<endl;
    ui->label_2->setText(userbeach);
}

void beach::on_exit_clicked()
{
    this->hide(); // 기존 창 닫기
    menu menu(userid, userbeach, userfacility, userguide); // 객체 생성
    menu.setModal(true); // 정보찾기창 열기
    menu.exec(); // 정보찾기창 닫으면
    this->show();
}
