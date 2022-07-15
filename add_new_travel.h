#ifndef ADD_NEW_TRAVEL_H
#define ADD_NEW_TRAVEL_H

#include <QDialog>
#include "con_DB_rent_car.h"

namespace Ui {
class Add_new_travel;
}

class Add_new_travel : public QDialog
{
    Q_OBJECT

public:
    explicit Add_new_travel(QWidget *parent = nullptr);
    ~Add_new_travel();

private slots:
    void on_add_Btn_clicked();

private:
    std::string query_string;
    QSqlQuery query;
    Ui::Add_new_travel *ui;
};

#endif // ADD_NEW_TRAVEL_H
