#include "database.h"
#include "server.h"
using namespace std;

void manage::read_member() // 준회원 정보 열람
{
    cout << "준회원 정보열람" << endl;
    sprintf(query, "select count(*) from usertbl where vip != 'vip'"); // 유저테이블에서 준회원이 있는지 검색
    send_query(query);
    sql_result = mysql_store_result(connection);
    if (*sql_row[0] == '0') // 정보가 없을 경우
    {
        cout << "등록된 준회원이 없습니다." << endl;
    }
    else
    {
        sprintf(query, "select id, pw, name, phone from usertbl where vip != 'vip'"); // 유저테이블에서 준회원정보 가져옴
        send_query(query);
        sql_result = mysql_store_result(connection);
        cout << "등록된 회원정보" << endl;
        while ((sql_row = mysql_fetch_row(sql_result)) != NULL) // 데이터를 모두 출력
        {
            cout << "아이디: " << id << " 비밀번호: " << pw << " 이름: " << name << " 전화번호: " << phone << endl;
        }
    }
}

void manage::read_vipmember() // vip회원 정보 열람
{
    cout << "vip회원 정보열람" << endl;
    sprintf(query, "select count(*) from usertbl where vip = 'vip'"); // 유저테이블에서 vip회원이 있는지 검색
    send_query(query);
    sql_result = mysql_store_result(connection);
    if (*sql_row[0] == '0') // 정보가 없을 경우
    {
        cout << "등록된 준회원이 없습니다." << endl;
    }
    else
    {
        sprintf(query, "select id, pw, name, phone from usertbl where vip = 'vip'"); // 유저테이블에서 vip회원정보 가져옴
        send_query(query);
        sql_result = mysql_store_result(connection);
        cout << "등록된 회원정보" << endl;
        while ((sql_row = mysql_fetch_row(sql_result)) != NULL) // 데이터를 모두 출력
        {
            cout << "아이디: " << sql_row[0] << " 비밀번호: " << sql_row[1] << " 이름: " << sql_row[2] << " 전화번호: " << sql_row[3] << endl;
        }
    }
}

void manage::read_reserve_stay() // 숙소 예약현황 열람
{
    // 미구현
}

void manage::read_reserve_tour() // 관광지 예약현황 열람
{
    cout << "관광지 예약현황" << endl;
    sprintf(query, "select count(*) from reservetbl"); // 예약테이블 모두 가져옴
    send_query(query);
    sql_result = mysql_store_result(connection);
    if (*sql_row[0] == '0') // 정보가 없을 경우
    {
        cout << "예약된 내역이 없습니다." << endl;
    }
    else // 예약된 정보가 있을 경우
    {
        sprintf(query, "select * from reservetbl"); // 예약테이블 모두 가져옴
        send_query(query);
        sql_result = mysql_store_result(connection);
        cout << "예약정보" << endl;
        while ((sql_row = mysql_fetch_row(sql_result)) != NULL) // 데이터를 모두 출력
        {
            cout << "아이디: " << sql_row[0] << " 해변명: " << sql_row[1] << endl;
        }
    }
}

void manage::read_order_guide() // 가이드 요청유무 열람
{
    cout << "가이드 요청 열람" << endl;
    sprintf(query, "select count(*) from usertbl where guide = '가이드요청"); // 유저테이블에서 가이드요청한 사람검색
    send_query(query);
    sql_result = mysql_store_result(connection);
    if (*sql_row[0] == '0') // 정보가 없을 경우
    {
        cout << "가이드 요청내역이 없습니다." << endl;
    }
    else // 요청한 정보가 있을 경우
    {
        sprintf(query, "select id from usertbl where guide = '가이드요청'"); // 해당하는 정보를 모두 가져옴
        send_query(query);
        sql_result = mysql_store_result(connection);
        cout << "가이드 요청 회원" << endl;
        while ((sql_row = mysql_fetch_row(sql_result)) != NULL) // 데이터를 모두 출력
        {
            cout << "아이디: " << sql_row[0] << endl;
        }
    }
}