#ifndef __DATABASE_H_
#define __DATABASE_H_
#include "/usr/include/mysql/mysql.h"
#include <iostream>
#include <string>
using namespace std;

class Database // 데이터베이스
{
public:
    MYSQL *connection = NULL, conn;
    MYSQL_RES *sql_result;
    MYSQL_ROW sql_row;
    int Stat;
    Database() // 생성자
    {
        mysql_init(&conn);
        mysql_options(&conn, MYSQL_SET_CHARSET_NAME, "utf8"); // 한글이 깨지는 현상 방지
        connection = mysql_real_connect(&conn, "10.10.20.42", "admin", "admin1234", "test", 3306, NULL, 0);
        if (connection == NULL)
        {
            fprintf(stderr, "Failed to connect to databases: Error: %s\n",
                    mysql_error(&conn));
            return;
        }
        else
        {
            puts("Database connect!");
        }
    }
    void send_query(char *query) // 원하는 쿼리문 보내기
    {
        char *Query = query;
        if (mysql_query(connection, Query) != 0)
        {
            fprintf(stderr, "Mysql query error : %s\n", mysql_error(&conn));
            exit(1);
        }
    }
};
#endif