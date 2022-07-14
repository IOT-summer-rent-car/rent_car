#include "add_new_car.h"
#include "ui_add_new_car.h"

Add_new_car::Add_new_car(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_new_car)
{
    ui->setupUi(this);
}

Add_new_car::~Add_new_car()
{
    delete ui;
}

void Add_new_car::on_add_clicked()
{
    if(ui->name->text() != "")
    {
        query.prepare("INSERT INTO cars(name,kind,data,rent,price) "
                      "VALUES (?, ?, ?, ? ,?)");

        query.addBindValue(ui->name->text());
        query.addBindValue(ui->kind->text());
        query.addBindValue(ui->data->text());
        query.addBindValue("X");
        query.addBindValue(ui->price->text());
        query.exec();

        this->close();
    }
}
