#ifndef ADD_NEW_CAR_H
#define ADD_NEW_CAR_H

#include <QDialog>
#include "con_DB_rent_car.h"

namespace Ui {
class Add_new_car;
}

class Add_new_car : public QDialog
{
    Q_OBJECT

public:
    explicit Add_new_car(QWidget *parent = nullptr);
    ~Add_new_car();

private slots:
    void on_add_clicked();

private:
    std::string query_string;
    QSqlQuery query;
    Ui::Add_new_car *ui;
};

#endif // ADD_NEW_CAR_H
