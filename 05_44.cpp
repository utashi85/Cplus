#include <iostream>
#include <chrono>
#include <ctime>
#include <time.h>
#include <string>
#include <sstream>

using namespace std;

class day_c
{
private:
    char dayofweek[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

public:
    void calendar(uint16_t y, uint16_t m);
};

inline time_t getTimeDay(uint16_t y, uint16_t m, uint16_t d)
{
    struct tm tm;

    tm.tm_sec = 0;
    tm.tm_min = 0;
    tm.tm_hour = 0;
    tm.tm_mday = d;
    tm.tm_mon = m - 1;
    tm.tm_year = y - 1900;
    tm.tm_isdst = -1;

    return mktime(&tm);
}

inline uint16_t getday(time_t dayTime)
{
    return localtime(&dayTime)->tm_mday;
}

inline uint8_t getWday(time_t dayTime)
{
    return localtime(&dayTime)->tm_wday;
}

inline string strSpace()
{
    return "    ";
}

inline string strDay(uint16_t day)
{
    stringstream retSs;
    retSs << (day > 9 ? "__" : "___") << day;
    return retSs.str();
}

void day_c::calendar(uint16_t y, uint16_t m)
{
    uint16_t cnt_day = 1;
    uint16_t nowWday = 0;

    cout << y << "/" << m << endl;

    for (uint16_t cnt_wday = 0; cnt_wday < 7; cnt_wday++)
    {
        cout << " " << dayofweek[cnt_wday];
    }
    cout << endl;

    while (cnt_day < 32)
    {
        time_t dayTime = getTimeDay(y, m, cnt_day);
        if (cnt_day != getday(dayTime))
        {
            break;
        }

        /** 曜日合わせ */
        while (nowWday == getWday(dayTime))
        {
            strSpace();
        }

        cout << strDay(cnt_day);
        cnt_day++;
        nowWday++;
        if (7 == nowWday)
        {
            nowWday = 0;
            cout << endl;
        }
    }
    cout << endl;
}

int main()
{
    day_c test;
    test.calendar(2019, 6);
    test.calendar(2019, 7);

    return 0;
}
