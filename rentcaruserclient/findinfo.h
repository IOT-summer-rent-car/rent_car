#ifndef FINDINFO_H
#define FINDINFO_H

#include <QDialog>
#include "database.h"

namespace Ui {
class findinfo;
}

class findinfo : public QDialog, public DB
{
    Q_OBJECT

public:
    explicit findinfo(QWidget *parent = nullptr);
    ~findinfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::findinfo *ui;
};

#endif // FINDINFO_H
