#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "database.h"

namespace Ui {
class menu;
}

class menu : public QDialog, public DB
{
    Q_OBJECT
    QString userid;
    QString userbeach;
    QString userfacility;
    QString userguide;

public:
    explicit menu(QString id = NULL, QString beachname = NULL, QString facility = NULL, QString guidename = NULL, QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
