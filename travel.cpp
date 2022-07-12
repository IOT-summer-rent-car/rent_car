#include "travel.h"
#include "ui_travel.h"

Travel::Travel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Travel)
{
    ui->setupUi(this);
    refresh();
}

Travel::~Travel()
{
    delete ui;
}

void Travel::refresh()
{
    ui->list->clear();
    int line=0;
    QStringList head= {"Name","Address"};
    ui->list->setHorizontalHeaderLabels(head);
    query_string = "SELECT * FROM travel";
    query.exec(QString::fromStdString(query_string));
    ui->list->setRowCount(query.size());
    while(query.next())
    {
        for(int i=0; i<2; i++)
        {
            ui->list->setItem(line, i, new QTableWidgetItem(query.value(i).toString()));
        }
        line++;
    }
    ui->list->show();
}

void Travel::on_list_cellClicked(int row)
{
    QList<QTableWidgetItem> list;
    row = ui->list->currentRow();

    for(int i =0; i<2; i++)
    {
        list.append(*(ui->list->takeItem(row,i)));
    }
    ui->name->setText(list.value(0).text());
    ui->addr->setText(list.value(1).text());
    slt_name = list.value(0).text();
    slt_addr = list.value(1).text();
    refresh();
}

void Travel::on_fix_btn_clicked()
{
    if(ui->name->text() != "")
    {
        query.prepare("UPDATE travel SET name = '"+ui->name->text()+"', addr = '"+ui->addr->text()
                      +"' WHERE name = '"+slt_name+"' and addr = '"+slt_addr+"'");
        query.exec();
        refresh();
    }
}

void Travel::on_remove_btn_clicked()
{
    if(slt_name != "")
    {
        query.prepare("DELETE FROM travel WHERE name='"+slt_name+"' and addr = '"+slt_addr+"'");
        query.exec();
        refresh();
    }
}

void Travel::on_add_btn_clicked()
{
    Add_new_travel add;
    add.setModal(true);
    add.exec();
    refresh();
}
