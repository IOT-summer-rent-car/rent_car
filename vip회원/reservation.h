#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDialog>
#include "database.h"

namespace Ui {
class reservation;
}

class reservation : public QDialog
{
    Q_OBJECT
    QString userid;
    QString userbeach;
    QString userfacility;
    QString userguide;

public:
    explicit reservation(QString id = NULL, QString beachname = NULL, QString facility = NULL, QString guidename = NULL, QWidget *parent = nullptr);
    ~reservation();

private slots:
    void on_calendarWidget_clicked();

private:
    Ui::reservation *ui;
};

#endif // RESERVATION_H
