#ifndef RESERV_H
#define RESERV_H

#include <QDialog>
#include "change_date.h"
#include "con_DB_rent_car.h"

namespace Ui {
class Reserv;
}

class Reserv : public QDialog
{
    Q_OBJECT

public:
    explicit Reserv(QWidget *parent = nullptr);
    ~Reserv();

private slots:
    void refresh();
    void on_list_cellClicked(int row);

    void on_fix_clicked();

private:
    std::string query_string;
    QSqlQuery query;
    Ui::Reserv *ui;
};

#endif // RESERV_H
