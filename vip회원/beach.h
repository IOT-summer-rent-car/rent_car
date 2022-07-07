#ifndef BEACH_H
#define BEACH_H

#include <QDialog>
#include "database.h"
#include "menu.h"

namespace Ui {
class beach;
}

class beach : public QDialog, public DB
{
    Q_OBJECT
    QString userid;
    QString userbeach;
    QString userfacility;
    QString userguide;

public:
    explicit beach(QString id = NULL, QString beachname = NULL, QString facility = NULL, QString guidename = NULL, QWidget *parent = nullptr);
    ~beach();

private slots:
    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

    void on_tableWidget_cellDoubleClicked();

    void on_exit_clicked();

private:
    Ui::beach *ui;
};

#endif // BEACH_H
