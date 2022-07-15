#ifndef CARSEARCH_H
#define CARSEARCH_H

#include <QDialog>
#include "database.h"
#include "menu.h"

namespace Ui {
class carsearch;
}

class carsearch : public QDialog, public DB
{
    Q_OBJECT
    QString userid;
    QString carname;

public:
    explicit carsearch(QString id = NULL, QWidget *parent = nullptr);
    ~carsearch();

private slots:
    void on_tableWidget_cellDoubleClicked();

    void on_exit_clicked();

    void on_search_clicked();

    void on_reserv_clicked();

private:
    Ui::carsearch *ui;
};

#endif // CARSEARCH_H
