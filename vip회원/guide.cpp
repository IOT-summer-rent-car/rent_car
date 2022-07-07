#include "guide.h"
#include "ui_guide.h"
#include "menu.h"

Guide::Guide(QString id, QString beachname, QString facility, QString guidename, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Guide)
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

Guide::~Guide()
{
    delete ui;
}

void Guide::on_lineEdit_returnPressed()
{
    QSqlQuery query;
    QSqlRecord rec;
    QString SQL, keyword;
    ui->tableWidget->setRowCount(0);
    keyword = ui->lineEdit->text(); // lineedit에 입력한 것을 keyword라는 변수에 저장
    SQL="SELECT * FROM guideTB where guideName LIKE '%"+keyword+"%'";
    query.exec(SQL);
    rec=query.record();
    while(query.next())
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(query.value(1).toString()));
    }
}

void Guide::on_pushButton_clicked()
{
    on_lineEdit_returnPressed();
}

void Guide::on_tableWidget_cellDoubleClicked()
{
    userguide = ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text();
    qDebug()<<userguide<<endl;
    ui->label_2->setText(userguide);
}

void Guide::on_exit_clicked()
{
    this->hide(); // 기존 창 닫기
    menu menu(userid, userbeach, userfacility, userguide); // 객체 생성
    menu.setModal(true); // 창 열기
    menu.exec(); // 창 닫으면
    this->show();
}
