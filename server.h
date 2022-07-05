#ifndef __SERVER_H__
#define __SERVER_H__

#include <iostream>
#include "database.h"
using namespace std;

class manage : public Database
{
public:
    char query[30];
    void read_member();       // 준회원 정보 열람
    void read_vipmember();    // vip회원 정보 열람
    void read_reserve_stay(); // 숙소 예약현황 열람
    void read_reserve_tour(); // 관광지 예약현황 열람
    void read_order_guide();  // 가이드 요청유무 열람
};

#endif