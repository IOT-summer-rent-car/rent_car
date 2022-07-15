#ifndef CARRENT_H
#define CARRENT_H

#include <QDialog>
#include "database.h"

namespace Ui {
class carrent;
}

class carrent : public QDialog
{
    Q_OBJECT
    QString userid;
    QString carname;

public:
    explicit carrent(QString id, QString car_name, QWidget *parent = nullptr);
    ~carrent();

private slots:
    void on_calendarWidget_clicked();

    void on_exit_clicked();

private:
    Ui::carrent *ui;
};

#endif // CARRENT_H
