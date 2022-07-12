#include "change_vip.h"
#include "ui_change_vip.h"

Change_VIP::Change_VIP(QString saved_id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Change_VIP)
{
    ui->setupUi(this);
    id = saved_id;
    ui->list->clear();
    QStringList list= {"VVIP","VIP","N"};
    for(auto &a:list)
    {
        ui->list->addItem(a);
    }
}

Change_VIP::~Change_VIP()
{
    delete ui;
}


void Change_VIP::on_choice_clicked()
{
    foreach( QListWidgetItem *item, ui->list->selectedItems())
        save_choice = item->text();

    if(save_choice != "")
    {
        query.prepare("UPDATE user SET vip = '"+save_choice+"' Where id = '"+id+"'");
        query.exec();

        this->close();
    }else
        QMessageBox::information(this,"","등급을 선택해주세요");
}

QString Change_VIP::return_vip()
{
    return save_choice;
}
