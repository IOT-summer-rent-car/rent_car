// #ifndef __DATABASE_H_
// #define __DATABASE_H_f
#include "/usr/include/mysql/mysql.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
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
    ~Database() // 소멸자
    {
        mysql_close(connection);
    }
    void sendquery(char *query) // 원하는 쿼리문 보내기
    {
        char *Query = query;
        if (mysql_query(connection, Query) != 0)
        {
            fprintf(stderr, "Mysql query error : %s\n", mysql_error(&conn));
            exit(1);
        }
    }
    void playquery(int num) // 원하는 갯수만큼 쿼리문 실행
    {
        sql_result = mysql_store_result(connection);
        while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
        {
            for (int i = 0; i < num; i++)
            {
                cout << sql_row[i];
            }
            cout << endl;
        }
        mysql_free_result(sql_result);
    }
};

int main(void)
{
    Database db;
    db.sendquery("select * from tourist");
    db.playquery(8);
    return 0;
}