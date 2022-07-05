#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <iostream>
#include <string>
#include "database.h"
using namespace std;

class member : public Database
{
protected:
    char id[30];
    char pw[30];
    char name[30];
    char phone[30];
    char query[200];

public:
    static string ID;
    void login();                       // 로그인
    void find_id();                     // 아이디 찾기
    void find_pw();                     // 비밀번호 찾기
    void sign_up();                     // 회원가입
    void change_pw();                   // 비밀번호 변경
    void change_phone();                // 전화번호 변경
    void read_tourinfo_area();  // 여행정보 지역이름으로 열람
    void read_tourinfo_beach(); // 여행정보 해변명으로 열람
    void read_tourinfo_road();  // 여행정보 도로명으로 열람
};

#endif