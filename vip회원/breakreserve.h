#ifndef BREAKRESERVE_H
#define BREAKRESERVE_H

#include <QDialog>
#include "database.h"
#include "menu.h"

namespace Ui {
class breakreserve;
}

class breakreserve : public QDialog, public DB
{
    Q_OBJECT
    QString userid;
    QString userbeach;
    QString userfacility;
    QString userguide;
    QString date;

public:
    explicit breakreserve(QString id = NULL, QString beachname = NULL, QString facility = NULL, QString guidename = NULL, QWidget *parent = nullptr);
    ~breakreserve();

private slots:
    void on_exit_clicked();

    void on_tableWidget_cellDoubleClicked();

    void on_breakbt_clicked();

private:
    Ui::breakreserve *ui;
};

#endif // BREAKRESERVE_H
