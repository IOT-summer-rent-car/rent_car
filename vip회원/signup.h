#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "database.h"

namespace Ui {
class signup;
}

class signup : public QDialog, public DB
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

    void on_lineEdit_3_textChanged();

    void on_pushButton_2_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
