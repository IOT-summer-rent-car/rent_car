#ifndef CHANGE_DATE_H
#define CHANGE_DATE_H

#include <QDialog>
#include "con_DB_rent_car.h"

namespace Ui {
class Change_date;
}

class Change_date : public QDialog
{
    Q_OBJECT

public:
    QString return_date();
    explicit Change_date(QString S_id,QString S_name,QString S_car_name, QString S_slt_date, QWidget *parent = nullptr);
    ~Change_date();

private slots:
    void on_slt_clicked();

private:
    std::string query_string;
    QSqlQuery query;

    QString id;
    QString name;
    QString car_name;
    QString slt_date;
    Ui::Change_date *ui;
};

#endif // CHANGE_DATE_H
