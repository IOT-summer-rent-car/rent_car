#ifndef GUIDE_H
#define GUIDE_H

#include <QDialog>
#include "database.h"

namespace Ui {
class Guide;
}

class Guide : public QDialog
{
    Q_OBJECT
    QString userid;
    QString userbeach;
    QString userfacility;
    QString userguide;

public:
    explicit Guide(QString id = NULL, QString beachname = NULL, QString facility = NULL, QString guidename = NULL, QWidget *parent = nullptr);
    ~Guide();

private slots:
    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

    void on_tableWidget_cellDoubleClicked();

    void on_exit_clicked();

private:
    Ui::Guide *ui;
};

#endif // GUIDE_H
