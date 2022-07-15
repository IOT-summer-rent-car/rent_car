#include "add_new_travel.h"
#include "ui_add_new_travel.h"

Add_new_travel::Add_new_travel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_new_travel)
{
    ui->setupUi(this);
}

Add_new_travel::~Add_new_travel()
{
    delete ui;
}

void Add_new_travel::on_add_Btn_clicked()
{
    if(ui->name->text() != "" && ui->addr->text() != "")
    {
        query.prepare("INSERT INTO travel(name,addr) "
                      "VALUES (?, ?)");

        query.addBindValue(ui->name->text());
        query.addBindValue(ui->addr->text());

        query.exec();
        this->close();
    }
}
