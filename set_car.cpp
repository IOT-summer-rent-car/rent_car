#include "set_car.h"
#include "ui_set_car.h"

set_car::set_car(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::set_car)
{
    ui->setupUi(this);
    refresh();
}

set_car::~set_car()
{
    delete ui;
}

void set_car::refresh()
{
    ui->list->clear();
    int line=0;
    QStringList head= {"Name","Kind","Data","Price","Rent"};
    ui->list->setHorizontalHeaderLabels(head);
    query_string = "SELECT * FROM cars ORDER BY price";
    query.exec(QString::fromStdString(query_string));
    ui->list->setRowCount(query.size());
    while(query.next())
    {
        for(int i=0; i<5; i++)
            ui->list->setItem(line, i, new QTableWidgetItem(query.value(i).toString()));
        line++;
    }
    ui->list->show();
}

void set_car::on_list_cellClicked(int row)
{
    QList<QTableWidgetItem> list;
    row = ui->list->currentRow();

    for(int i =0; i<5; i++)
    {
        list.append(*(ui->list->takeItem(row,i)));
    }

    slt_name = list.value(0).text();
    slt_kind = list.value(1).text();
    slt_data = list.value(2).text();
    slt_price = list.value(4).text();
    ui->name->setText(slt_name);
    ui->kind->setText(slt_kind);
    ui->data->setText(slt_data);
    ui->price->setText(slt_price);
    refresh();
}

void set_car::on_fix_clicked()
{
    if(slt_name != "")
    {
        query.prepare("UPDATE cars SET name = '"+ui->name->text()+"', kind = '"+ui->kind->text()+"', data = '"+ui->data->text()+"', price ='"+ui->price->text()+
                       "' WHERE name = '"+slt_name+"' and kind = '"+slt_kind+"'and data = '"+slt_data+"' and price = '"+slt_price+"'");
        query.exec();
        refresh();
    }
}

void set_car::on_remove_clicked()
{
    if(slt_name != "")
    {
        query.prepare("DELETE FROM cars WHERE name = '"+slt_name+"' and kind = '"+slt_kind+"'and data = '"+slt_data+"' and price = '"+slt_price+"'");
        query.exec();
        refresh();
    }
}

void set_car::on_add_clicked()
{
    Add_new_car add;
    add.setModal(true);
    add.exec();
    refresh();
}
