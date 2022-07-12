#include "user_info.h"
#include "ui_user_info.h"

user_info::user_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_info)
{
    ui->setupUi(this);
    refresh();
}

user_info::~user_info()
{
    delete ui;
}

void user_info::refresh()
{
    ui->list->clear();
    int line=0;
    QStringList head= {"ID","Name","VIP","Money","used"};
    ui->list->setHorizontalHeaderLabels(head);
    query_string = "SELECT * FROM user";
    query.exec(QString::fromStdString(query_string));
    ui->list->setRowCount(query.size());
    while(query.next())
    {
        for(int i=0; i<5; i++)
        {
            ui->list->setItem(line, i, new QTableWidgetItem(query.value(i).toString()));
        }
        line++;
    }
    ui->list->show();
}

void user_info::on_change_vi_Btn_clicked()
{
    if(saved_choice != "")
    {
        Change_VIP C_V(saved_choice);
        C_V.setModal(true);
        C_V.exec();
        QString temp = C_V.return_vip();
        if (temp != "")
        {
            ui->change_vip->setText(temp);
        }
        refresh();
    }
}

void user_info::on_list_cellClicked(int row)
{
    QList<QTableWidgetItem> list;
    row = ui->list->currentRow();

    for(int i =0; i<4; i++)
    {
        list.append(*(ui->list->takeItem(row,i)));
    }

    ui->change_name->setText(list.value(1).text());
    ui->change_vip->setText(list.value(2).text());
    ui->slt_id->setText(list.value(0).text());
    saved_choice = list.value(0).text();
    refresh();
}

void user_info::on_change_name_Btn_clicked()
{
    QString C_name = ui->change_name->text();
    if(ui->change_name->text() != "")
    {
        query.prepare("UPDATE user SET name = '"+C_name+"' Where id = '"+ui->slt_id->text()+"'");
        query.exec();

        refresh();
    }else
        QMessageBox::information(this,"","공백임");
}
