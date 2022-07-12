#include "reserv.h"
#include "ui_reserv.h"

Reserv::Reserv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reserv)
{
    ui->setupUi(this);
    refresh();
}

Reserv::~Reserv()
{
    delete ui;
}

void Reserv::refresh()
{
    ui->list->clear();
    int line=0;
    QStringList head= {"ID","Name","Car_Name","DATE"};
    ui->list->setHorizontalHeaderLabels(head);
    query_string = "SELECT * FROM reserv";
    query.exec(QString::fromStdString(query_string));
    ui->list->setRowCount(query.size());
    while(query.next())
    {
        for(int i=0; i<4; i++)
            ui->list->setItem(line, i, new QTableWidgetItem(query.value(i).toString()));
        line++;
    }
    ui->list->show();
}

void Reserv::on_list_cellClicked(int row)
{
    QList<QTableWidgetItem> list;
    row = ui->list->currentRow();

    for(int i =0; i<4; i++)
    {
        list.append(*(ui->list->takeItem(row,i)));
    }
    ui->id->setText(list.value(0).text());
    ui->name->setText(list.value(1).text());
    ui->car_name->setText(list.value(2).text());
    ui->date->setText(list.value(3).text());
    refresh();
}

void Reserv::on_fix_clicked()
{
    Change_date date(ui->id->text(), ui->name->text(), ui->car_name->text(), ui->date->text());
    date.setModal(true);
    date.exec();
    ui->date->setText(date.return_date());
    refresh();
}
