#include "main_page.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    con_db_rent_car c;
    QApplication a(argc, argv);
    Main_Page w;
    w.show();
    return a.exec();
}
