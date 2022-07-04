#include "database.h"
#include "client.h"
#include "vipclient.h"
using namespace std;

void member::read_tourinfo_area() // 여행정보 지역이름으로 열람 및 예약
{
    char choice;
    string area;
    cout << "지역이름으로 여행정보 검색" << endl;
    cout << "지역이름을 입력해주세요." << endl;
    cin >> area;
    sprintf(query, "select count(*) from tourist where 시군명 like '%%%s%%'", area.c_str()); // 입력한 지역에 해당하는 정보가 있는지 검색
    send_query(query);
    sql_result = mysql_store_result(connection);
    sql_row = mysql_fetch_row(sql_result);
    if (*sql_row[0] == '0') // 정보가 없을 경우
    {
        cout << "검색결과가 없습니다." << endl;
    }
    else
    {
        sprintf(query, "select * from tourist where 시군명 like '%%%s%%'", area.c_str()); // 해당하는 정보 테이블로 가져옴
        send_query(query);
        sql_result = mysql_store_result(connection);
        while ((sql_row = mysql_fetch_row(sql_result)) != NULL) // 데이터를 모두 출력
        {
            cout << "시군명: " << sql_row[0] << " 해변명: " << sql_row[1] << " 주요내용: " << sql_row[2] << " 도로명주소: " << sql_row[3] << " 전화번호: " << sql_row[4] << " 입장료: " << sql_row[5] << " 주차시설: " << sql_row[6] << " 주변명소: " << sql_row[7] << endl;
        }
    }
    cout << "예약하시겠습니까?" << endl;
    cout << "네) y   아니오) n" << endl;
    cin >> choice;
    if (choice == 'y')
    {
        cout << "예약하실 해변 이름을 정확히 입력해주세요." << endl;
        cin >> area;
        sprintf(query, "select count(*) from tourist where 해변명 = '%s'", area.c_str()); // 입력한 해변명에 해당하는 관광지 검색
        send_query(query);
        if (*sql_row[0] == '0') // 해당하는 관광지가 존재하지 않을 경우
        {
            cout << "해당하는 관광지가 없습니다." << endl;
        }
        else // 해당하는 관광지가 존재할 경우
        {
            sprintf(query, "insert into reservetbl values( '%s', '%s')", member::ID.c_str(), area.c_str()); // 예약테이블에 예약한 해변명 등록
            send_query(query);
            cout << "예약 완료했습니다." << endl;
        }
    }
}

void member::read_tourinfo_beach() // 여행정보 해변명으로 열람 및 예약
{
    char choice;
    string beach;
    cout << "해변명으로 여행정보 검색" << endl;
    cout << "해변명을 입력해주세요." << endl;
    cin >> area;
    sprintf(query, "select count(*) from tourist where 해변명 like '%%%s%%'", beach.c_str()); // 입력한 해변명에 해당하는 정보가 있는지 검색
    send_query(query);
    sql_result = mysql_store_result(connection);
    sql_row = mysql_fetch_row(sql_result);
    if (*sql_row[0] == '0') // 정보가 없을 경우
    {
        cout << "검색결과가 없습니다." << endl;
    }
    else
    {
        sprintf(query, "select * from tourist where 해변명 like '%%%s%%'", beach.c_str()); // 해당하는 정보 테이블로 가져옴
        send_query(query);
        sql_result = mysql_store_result(connection);
        while ((sql_row = mysql_fetch_row(sql_result)) != NULL) // 데이터를 모두 출력
        {
            cout << "시군명: " << sql_row[0] << " 해변명: " << sql_row[1] << " 주요내용: " << sql_row[2] << " 도로명주소: " << sql_row[3] << " 전화번호: " << sql_row[4] << " 입장료: " << sql_row[5] << " 주차시설: " << sql_row[6] << " 주변명소: " << sql_row[7] << endl;
        }
    }
    cout << "예약하시겠습니까?" << endl;
    cout << "네) y   아니오) n" << endl;
    cin >> choice;
    if (choice == 'y')
    {
        cout << "예약하실 해변 이름을 정확히 입력해주세요." << endl;
        cin >> beach;
        sprintf(query, "select count(*) from tourist where 해변명 = '%s'", beach.c_str()); // 입력한 해변명에 해당하는 관광지 검색
        send_query(query);
        if (*sql_row[0] == '0') // 해당하는 관광지가 존재하지 않을 경우
        {
            cout << "해당하는 관광지가 없습니다." << endl;
        }
        else // 해당하는 관광지가 존재할 경우
        {
            sprintf(query, "insert into reservetbl values( '%s', '%s')", member::ID.c_str(), beach.c_str()); // 예약테이블에 예약한 해변명 등록
            send_query(query);
            cout << "예약 완료했습니다." << endl;
        }
    }
}

void member::read_tourinfo_road() // 여행정보 도로명으로 열람 및 예약
{
    char choice;
    string road;
    cout << "도로명으로 여행정보 검색" << endl;
    cout << "도로명을 입력해주세요." << endl;
    cin >> road;
    sprintf(query, "select count(*) from tourist where 도로명주소 like '%%%s%%'", road.c_str()); // 입력한 도로명에 해당하는 정보가 있는지 검색
    send_query(query);
    sql_result = mysql_store_result(connection);
    sql_row = mysql_fetch_row(sql_result);
    if (*sql_row[0] == '0') // 정보가 없을 경우
    {
        cout << "검색결과가 없습니다." << endl;
    }
    else
    {
        sprintf(query, "select * from tourist where 도로명 like '%%%s%%'", road.c_str()); // 해당하는 정보 테이블로 가져옴
        send_query(query);
        sql_result = mysql_store_result(connection);
        while ((sql_row = mysql_fetch_row(sql_result)) != NULL) // 데이터를 모두 출력
        {
            cout << "시군명: " << sql_row[0] << " 해변명: " << sql_row[1] << " 주요내용: " << sql_row[2] << " 도로명주소: " << sql_row[3] << " 전화번호: " << sql_row[4] << " 입장료: " << sql_row[5] << " 주차시설: " << sql_row[6] << " 주변명소: " << sql_row[7] << endl;
        }
    }
    cout << "예약하시겠습니까?" << endl;
    cout << "네) y   아니오) n" << endl;
    cin >> choice;
    if (choice == 'y')
    {
        cout << "예약하실 해변 이름을 정확히 입력해주세요." << endl;
        cin >> road;
        sprintf(query, "select count(*) from tourist where 해변명 = '%s'", road.c_str()); // 입력한 해변명에 해당하는 관광지 검색
        send_query(query);
        if (*sql_row[0] == '0') // 해당하는 관광지가 존재하지 않을 경우
        {
            cout << "해당하는 관광지가 없습니다." << endl;
        }
        else // 해당하는 관광지가 존재할 경우
        {
            sprintf(query, "insert into reservetbl values( '%s', '%s')", member::ID.c_str(), road.c_str()); // 예약테이블에 예약한 해변명 등록
            send_query(query);
            cout << "예약 완료했습니다." << endl;
        }
    }
}

void member::sign_up() // 회원가입
{
    cout << "회원가입" << endl;
    cout << "아이디를 입력해주세요." << endl;
    cin >> id;
    sprintf(query, "select count(*) from usertbl where id = '%s'", id.c_str()); // 유저테이블에서 해당하는 id가 있는지 검색
    send_query(query);
    sql_result = mysql_store_result(connection);
    sql_row = mysql_fetch_row(sql_result);
    if (*sql_row[0] == '0') // 이미 등록된 id가 존재하는 경우
    {
        cout << "이미 등록된 id입니다." << endl;
    }
    else // 등록된 아이디가 없는 경우
    {
        cout << "비밀번호를 입력해주세요." << endl;
        cin >> pw;
        cout << "이름을 입력해주세요." << endl;
        cin >> name;
        cout << "전화번호를 입력해주세요." << endl;
        cin >> phone;
        sprintf(query, "insert into usertbl(id, pw, name, phone, vip) values('%s', '%s', '%s', '%s', 'vip')", id.c_str(), pw.c_str(), name.c_str(), phone.c_str()); // 입력받은 정보로 유저테이블에 등록
        send_query(query);
        cout << "회원가입이 완료되었습니다." << endl;
    }
}

void vipmember::order_guide() // 가이드 요청
{
    char choice;
    cout << "가이드 요청" << endl;
    cout << "가이드를 요청하시겠습니까?" << endl;
    cout << "네) y   아니오) n" << endl;
    if (choice == 'y')
    {
        sprintf(query, "update usertbl set guide = '가이드요청' where id = '%s'", member::ID.c_str()); // 유저테이블에 가이드 여부 등록
        send_query(query);
        cout << "요청되었습니다." << endl;
    }
}