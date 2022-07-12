#ifndef CHANGE_VIP_H
#define CHANGE_VIP_H

#include <QDialog>
#include <QList>
#include <QMessageBox>
#include <algorithm>
#include "con_DB_rent_car.h"

namespace Ui {
class Change_VIP;
}

class Change_VIP : public QDialog
{
    Q_OBJECT

public:
    QString return_vip();
    explicit Change_VIP(QString saved_id,QWidget *parent = nullptr);
    ~Change_VIP();

private slots:
    void on_choice_clicked();

private:
    std::string query_string;
    QSqlQuery query;

    QString id;
    QString save_choice;
    Ui::Change_VIP *ui;
};

#endif // CHANGE_VIP_H
