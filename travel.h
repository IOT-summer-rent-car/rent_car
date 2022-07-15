#ifndef TRAVEL_H
#define TRAVEL_H

#include <QDialog>
#include "add_new_travel.h"
#include "con_DB_rent_car.h"

namespace Ui {
class Travel;
}

class Travel : public QDialog
{
    Q_OBJECT

public:
    explicit Travel(QWidget *parent = nullptr);
    ~Travel();

private slots:
    void refresh();

    void on_list_cellClicked(int row);

    void on_fix_btn_clicked();

    void on_remove_btn_clicked();

    void on_add_btn_clicked();

private:
    std::string query_string;
    QSqlQuery query;

    QString slt_name;
    QString slt_addr;
    Ui::Travel *ui;
};

#endif // TRAVEL_H
