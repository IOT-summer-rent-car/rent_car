#ifndef FACILITY_H
#define FACILITY_H

#include <QDialog>
#include "database.h"

namespace Ui {
class facility;
}

class facility : public QDialog, public DB
{
    Q_OBJECT
    QString userid;
    QString userbeach;
    QString userfacility;
    QString userguide;

public:
    explicit facility(QString id = NULL, QString beachname = NULL, QString facility = NULL, QString guidename = NULL, QWidget *parent = nullptr);
    ~facility();

private slots:
    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

    void on_exit_clicked();

    void on_tableWidget_cellDoubleClicked();

private:
    Ui::facility *ui;
};

#endif // FACILITY_H
