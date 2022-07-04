#include "database.h"
#include "client.h"
#include <iostream>
#include <cstring>
using namespace std;

void member::login() // 로그인
{
    cout << "로그인" << endl;
    cout << "아이디를 입력해주세요." << endl;
    cin >> id;
    cout << "비밀번호를 입력해주세요." << endl;
    cin >> pw;
    sprintf(query, "select count(*) from usertbl where id = '%s'", id.c_str()); // 입력한 id가 유저테이블에 있는지 확인
    send_query(query);
    sql_result = mysql_store_result(connection);
    sql_row = mysql_fetch_row(sql_result);
    if (*sql_row[0] == '0') // 유저테이블에 입력한 id가 존재하지 않을 경우
    {
        cout << "등록되지 않은 id입니다." << endl;
    }
    else
    {
        sprintf(query, "select count(*) from usertbl where id = '%s' and pw = '%s'", id.c_str(), pw.c_str()); // 입력한 id와 pw가 유저테이블에 있는지 확인
        send_query(query);
        sql_result = mysql_store_result(connection);
        sql_row = mysql_fetch_row(sql_result);
        if (*sql_row[0] == '0') // id와 맞는 pw가 없을 경우
        {
            cout << "비밀번호를 확인해주세요." << endl;
        }
        else // 로그인 성공
        {
            ID = id;
            cout << "로그인 성공!" << endl;
        }
    }
}

void member::find_id() // 아이디 찾기
{
    cout << "아이디 찾기" << endl;
    cout << "이름을 입력해주세요." << endl;
    cin >> name;
    cout << "전화번호를 입력해주세요." << endl;
    cin >> phone;
    sprintf(query, "select count(*) from usertbl where name = '%s'", name.c_str()); // 입력한 이름이 유저테이블에 있는지 확인
    send_query(query);
    sql_result = mysql_store_result(connection);
    sql_row = mysql_fetch_row(sql_result);
    if (*sql_row[0] == '0') // 유저테이블에 입력한 이름이 존재하지 않을 경우
    {
        cout << "등록되지 않은 사용자입니다." << endl;
    }
    else
    {
        sprintf(query, "select count(*) from usertbl where name = '%s' and phone = '%s'", name.c_str(), phone.c_str()); // 입력한 이름과 전화번호가 유저테이블에 있는지 확인
        send_query(query);
        sql_result = mysql_store_result(connection);
        sql_row = mysql_fetch_row(sql_result);
        if (*sql_row[0] == '0') // 이름에 맞는 전화번호가 존재하지 않을 경우
        {
            cout << "전화번호를 잘못 입력하였습니다." << endl;
        }
        else
        {
            sprintf(query, "select id from usertbl where name = '%s' and phone = '%s'", name.c_str(), phone.c_str()); // 유저테이블에서 이름과 전화번호에 해당하는 id 가져옴
            send_query(query);
            sql_result = mysql_store_result(connection);
            sql_row = mysql_fetch_row(sql_result);
            cout << "아이디: " << sql_row[0] << endl;
        }
    }
}

void member::find_pw() // 비밀번호 찾기
{
    cout << "비밀번호 찾기" << endl;
    cout << "아이디를 입력해주세요." << endl;
    cin >> id;
    cout << "전화번호를 입력해주세요." << endl;
    cin >> phone;
    sprintf(query, "select count(*) from usertbl where id = '%s'", id.c_str()); // 입력한 id가 유저테이블에 있는지 확인
    send_query(query);
    sql_result = mysql_store_result(connection);
    sql_row = mysql_fetch_row(sql_result);
    if (*sql_row[0] == '0') // 유저테이블에 입력한 id가 존재하지 않을 경우
    {
        cout << "등록되지 않은 id입니다." << endl;
    }
    else
    {
        sprintf(query, "select count(*) from usertbl where id = '%s' and phone = '%s'", id.c_str(), phone.c_str()); // 입력한 id와 전화번호가 유저테이블에 있는지 확인
        send_query(query);
        sql_result = mysql_store_result(connection);
        sql_row = mysql_fetch_row(sql_result);
        if (*sql_row[0] == '0') // id에 맞는 전화번호가 존재하지 않을 경우
        {
            cout << "전화번호를 잘못 입력하였습니다." << endl;
        }
        else
        {
            sprintf(query, "select pw from usertbl where id = '%s' and phone = '%s'", id.c_str(), phone.c_str()); // 유저테이블에서 id와 전화번호에 해당하는 pw 가져옴
            send_query(query);
            sql_result = mysql_store_result(connection);
            sql_row = mysql_fetch_row(sql_result);
            cout << "비밀번호: " << sql_row[0] << endl;
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
        sprintf(query, "insert into usertbl(id, pw, name, phone) values('%s', '%s', '%s', '%s')", id.c_str(), pw.c_str(), name.c_str(), phone.c_str()); // 입력받은 정보로 유저테이블에 등록
        send_query(query);
        cout << "회원가입이 완료되었습니다." << endl;
    }
}

void change_pw() // 비밀번호 변경
{
    cout << "비밀번호 변경" << endl;
    cout << "변경할 비밀번호를 입력해주세요." << endl;
    cin >> pw;
    sprintf(query, "update usertbl set pw = '%s' where id = '%s'", pw.c_str(), ID.c_str()); // 로그인한 아이디에 해당하는 비밀번호 변경
    send_query(query);
    cout << "비밀번호가 " << pw << "로 변경되었습니다." << endl;
}

void change_phone() // 전화번호 변경
{
    cout << "번호 변경" << endl;
    cout << "변경할 번호를 입력해주세요." << endl;
    cin >> phone;
    sprintf(query, "update usertbl set phone = '%s' where id = '%s'", phone.c_str(), ID.c_str()); // 로그인한 아이디에 해당하는 전화번호 변경
    send_query(query);
    cout << "전화번호가 " << phone << "로 변경되었습니다." << endl;
}

void member::read_tourinfo_area() // 여행정보 지역이름으로 열람
{
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
}

void member::read_tourinfo_beach() // 여행정보 해변명으로 열람
{
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
}

void member::read_tourinfo_road() // 여행정보 도로명으로 열람
{
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
}