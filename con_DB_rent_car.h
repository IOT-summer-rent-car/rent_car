#ifndef CON_DB_H
#define CON_DB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QtSql>
#include <QDebug>
#include <QSqlTableModel>
#include <sstream>
#include <QList>
#include <iostream>

class con_db_rent_car
{
private:
    QSqlDatabase db;
public:
    con_db_rent_car() {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("10.10.20.232");      // IP 또는 DNS Host name
        db.setDatabaseName("rent_car"); // DB명
        db.setUserName("car");     // 계정 명
        db.setPassword("1234");     // 계정 Password

        if(!db.open())
        {
            qDebug()<<"실패";
            exit(1);
        }
    }
    ~con_db_rent_car() {
        db.close();
    }
};

#endif // CON_DB_H
