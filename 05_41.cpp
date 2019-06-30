#include <iostream>
#include <chrono>
#include <ctime>
#include <time.h>

using namespace std;

class day_c
{
private:
    time_t day_1;

public:
    void setDay1(uint16_t y, uint16_t m, uint16_t d);
    uint8_t wday(void);
};

void day_c::setDay1(uint16_t y, uint16_t m, uint16_t d)
{
    struct tm tmpday;

    tmpday.tm_sec = 0;
    tmpday.tm_min = 0;
    tmpday.tm_hour = 0;
    tmpday.tm_mday = d;
    tmpday.tm_mon = m - 1;
    tmpday.tm_year = y - 1900;
    tmpday.tm_isdst = -1;

    day_1 = mktime(&tmpday);
}

uint8_t day_c::wday(void)
{
    return localtime(&day_1)->tm_wday;
}

int main()
{
    day_c test;
    test.setDay1(2019, 6, 1);
    cout << "2019/6/1 : " << +test.wday() << endl;

    test.setDay1(2019, 5, 1);
    cout << "2019/5/1 : " << +test.wday() << endl;

    test.setDay1(2020, 6, 1);
    cout << "2020/6/1 : " << +test.wday() << endl;

    test.setDay1(2018, 6, 1);
    cout << "2018/6/1 : " << +test.wday() << endl;

    return 0;
}
