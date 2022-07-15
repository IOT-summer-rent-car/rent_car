#include "change_date.h"
#include "ui_change_date.h"

Change_date::Change_date(QString S_id,QString S_name,QString S_car_name, QString S_slt_date,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Change_date)
{
    ui->setupUi(this);
    id = S_id;
    name = S_name;
    car_name = S_car_name;
    slt_date = S_slt_date;
}

Change_date::~Change_date()
{
    delete ui;
}

QString Change_date::return_date()
{
    return slt_date;
}

void Change_date::on_slt_clicked()
{
    QString date = ui->calendar->selectedDate().toString("yyyy.MM.dd");
    query.prepare("UPDATE reserv SET date = '"+date+"' WHERE id = '"+id+
                  "'and name = '"+name+"'and car_name = '"+car_name+"' and date = '"+slt_date+"'");
    query.exec();
    slt_date = date;
    this->close();
}
