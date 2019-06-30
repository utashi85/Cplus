#include <iostream>
#include <chrono>
#include <ctime>
#include <time.h>

using namespace std;
#if 1
class day_c
{
private:
    time_t day_1;
    time_t day_2;

public:
    void setDay1(uint16_t y, uint16_t m, uint16_t d);
    void setDay2(uint16_t y, uint16_t m, uint16_t d);
    uint32_t between(void);
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

void day_c::setDay2(uint16_t y, uint16_t m, uint16_t d)
{
    struct tm tmpday;

    tmpday.tm_sec = 0;
    tmpday.tm_min = 0;
    tmpday.tm_hour = 0;
    tmpday.tm_mday = d;
    tmpday.tm_mon = m - 1;
    tmpday.tm_year = y - 1900;
    tmpday.tm_isdst = -1;

    day_2 = mktime(&tmpday);
}

inline uint32_t days(struct tm *tm)
{
    return tm->tm_year * 365 + tm->tm_yday;
}

uint32_t day_c::between(void)
{
    if (day_1 < day_2)
    {
        return days(localtime(&day_2)) - days(localtime(&day_1));
    }
    else
    {
        return days(localtime(&day_1)) - days(localtime(&day_2));
    }
}

#else
class ymd_c
{
private:
    uint16_t year;
    uint16_t month;
    uint16_t date;
    chrono::sys_days days_1;
    chrono::sys_days days_2;

public:
    void set1(uint16_t y, uint16_t m, uint16_t d);
    void set2(uint16_t y, uint16_t m, uint16_t d);
    uint16_t between();
};

void ymd_c::set1(uint16_t y, uint16_t m, uint16_t d)
{
    /** 書き方はこういうもの */
    days_1
    {
        year{y} / month{m} / day { d }
    }
}

void ymd_c::set2(uint16_t y, uint16_t m, uint16_t d)
{
    days_2
    {
        year{y} / month{m} / day { d }
    }
}

uint16_t between()
{
    uint16_t ret = 0;
    return days_1 > days_2 ? (days_2 - days_1).count() : (days_1 - days_2).count();
}
#endif

int main()
{
    day_c test;
    test.setDay1(2019, 6, 1);
    test.setDay2(2019, 6, 5);
    cout << "2019/6/1 - 2019/6/5 : " << test.between() << endl;

    test.setDay2(2019, 5, 1);
    cout << "2019/6/1 - 2019/5/1 : " << test.between() << endl;

    test.setDay2(2020, 6, 1);
    cout << "2019/6/1 - 2020/6/1 : " << test.between() << endl;

    test.setDay2(2018, 6, 1);
    cout << "2019/6/1 - 2018/6/1 : " << test.between() << endl;

    return 0;
}
