#include "findbeach.h"
#include "ui_findbeach.h"

findbeach::findbeach(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findbeach)
{
    ui->setupUi(this);
}

findbeach::~findbeach()
{
    delete ui;
}
