#ifndef SET_CAR_H
#define SET_CAR_H

#include <QDialog>
#include "con_DB_rent_car.h"
#include "add_new_car.h"

namespace Ui {
class set_car;
}

class set_car : public QDialog
{
    Q_OBJECT

public:
    explicit set_car(QWidget *parent = nullptr);
    ~set_car();

private slots:
    void refresh();
    void on_list_cellClicked(int row);

    void on_fix_clicked();

    void on_remove_clicked();

    void on_add_clicked();

private:
    std::string query_string;
    QSqlQuery query;
    QString slt_name;
    QString slt_kind;
    QString slt_data;
    QString slt_price;
    Ui::set_car *ui;
};

#endif // SET_CAR_H
