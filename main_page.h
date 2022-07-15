#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <QDialog>
#include "travel.h"
#include "user_info.h"
#include "set_car.h"
#include "reserv.h"
#include "chat.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Main_Page; }
QT_END_NAMESPACE

class Main_Page : public QDialog
{
    Q_OBJECT

public:
    Main_Page(QWidget *parent = nullptr);
    ~Main_Page();

private slots:
    void on_user_info_clicked();

    void on_travel_info_clicked();

    void on_car_info_clicked();

    void on_reserv_info_clicked();

    void on_chat_btn_clicked();

private:
    Ui::Main_Page *ui;
};
#endif // MAIN_PAGE_H
