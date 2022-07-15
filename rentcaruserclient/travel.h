#ifndef TRAVEL_H
#define TRAVEL_H

#include <QDialog>
#include "database.h"
#include "menu.h"

namespace Ui {
class travel;
}

class travel : public QDialog, public DB
{
    Q_OBJECT
    QString userid;
    QString travelname;

public:
    explicit travel(QString id = NULL, QWidget *parent = nullptr);
    ~travel();

private slots:
    void on_exit_clicked();

    void on_search_clicked();

private:
    Ui::travel *ui;
};

#endif // TRAVEL_H
