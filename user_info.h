#ifndef USER_INFO_H
#define USER_INFO_H

#include <QDialog>
#include "con_DB_rent_car.h"
#include "change_vip.h"

namespace Ui {
class user_info;
}

class user_info : public QDialog
{
    Q_OBJECT

public:
    explicit user_info(QWidget *parent = nullptr);
    ~user_info();

private slots:
    void refresh();
    void on_change_vi_Btn_clicked();

    void on_list_cellClicked(int row);

    void on_change_name_Btn_clicked();

private:
    std::string query_string;
    QSqlQuery query;
    QString saved_choice;
    Ui::user_info *ui;
};

#endif // USER_INFO_H
