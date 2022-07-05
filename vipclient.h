#ifndef __VIPCLIENT_H__
#define __VIPCLIENT_H__

#include <iostream>
#include "client.h"
using namespace std;

class vipmember : public member
{
public:
    void read_tourinfo_area();  // 여행정보 지역이름으로 열람 및 예약
    void read_tourinfo_beach(); // 여행정보 해변명으로 열람 및 예약
    void read_tourinfo_road();  // 여행정보 도로명으로 열람 및 예약
    void sign_up();                     // 회원가입
    void order_guide();                 // 가이드 요청
};

#endif