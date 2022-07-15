#ifndef TALK_H
#define TALK_H

#include <QDialog>
#include <QMessageBox>
#include <cstring>
#include <string>
#include "database.h"
#include "menu.h"
#include "thread.h"
#include "connect.h"

namespace Ui {
class talk;
}

class talk : public QDialog, public Connect
{
    Q_OBJECT
    QString userid;
    QString username;
    QString start_chat_date;

public:
    explicit talk(QString id = NULL, QWidget *parent = nullptr);
    ~talk();

private:
    Ui::talk *ui;
    Thread *thread;

private slots:
    void Receive(char* data);
    void on_lineEdit_returnPressed();
    void on_exit_clicked();
    void closeEvent(QCloseEvent *);
};

#endif // TALK_H
