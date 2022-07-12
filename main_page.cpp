#include "main_page.h"
#include "ui_main_page.h"


Main_Page::Main_Page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Main_Page)
{
    ui->setupUi(this);
}

Main_Page::~Main_Page()
{
    delete ui;
}


void Main_Page::on_user_info_clicked()
{
    this->hide();
    user_info user;
    user.setModal(true);
    user.exec();
    this->show();
}

void Main_Page::on_travel_info_clicked()
{
    this->hide();
    Travel T;
    T.setModal(true);
    T.exec();
    this->show();
}

void Main_Page::on_car_info_clicked()
{
    this->hide();
    set_car car;
    car.setModal(true);
    car.exec();
    this->show();
}

void Main_Page::on_reserv_info_clicked()
{
    this->hide();
    Reserv reserv;
    reserv.setModal(true);
    reserv.exec();
    this->show();
}

void Main_Page::on_chat_btn_clicked()
{
    this->hide();
    Chat c;
    c.setModal(true);
    c.exec();
    this->show();
}
