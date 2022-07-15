#ifndef RESERV_H
#define RESERV_H

#include <QDialog>
#include "database.h"
#include "menu.h"

namespace Ui {
class reserv;
}

class reserv : public QDialog, public DB
{
    Q_OBJECT
    QString userid;
    QString car_name;

public:
    explicit reserv(QString id = NULL, QWidget *parent = nullptr);
    ~reserv();

private slots:
    void on_tableWidget_cellDoubleClicked();

    void on_pushButton_clicked();

    void on_exit_clicked();

private:
    Ui::reserv *ui;
};

#endif // RESERV_H
