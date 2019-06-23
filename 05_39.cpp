#include <iostream>
#include <time.h>
#include <windows.h>
#include <chrono>

#define LOOPMAX ((2) ^ (32))

using namespace std;

void looploop()
{
    uint8_t tmp = 0;
    for (uint32_t cnt = 0; cnt < LOOPMAX; cnt++)
        for (uint32_t cnt1 = 0; cnt1 < LOOPMAX; cnt1++)
            for (uint32_t cnt2 = 0; cnt2 < LOOPMAX; cnt2++)
                for (uint32_t cnt3 = 0; cnt3 < LOOPMAX; cnt3++)
                    for (uint32_t cnt4 = 0; cnt4 < LOOPMAX; cnt4++)
                        tmp++;
}

void useClock()
{
    clock_t start = clock();

    looploop();

    clock_t end = clock();

    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "time " << time << "[ms]" << endl;
}

void useQueryPerformanceCounter()
{
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);

    LARGE_INTEGER start, end;

    QueryPerformanceCounter(&start);

    looploop();

    QueryPerformanceCounter(&end);

    double time = static_cast<double>(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
    cout << "time " << time << "[ms]" << endl;
}

void useSystemClock()
{
    chrono::system_clock::time_point start, end;

    start = chrono::system_clock::now();

    looploop();

    end = chrono::system_clock::now();

    double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
    cout << "time " << time << "[ms]" << endl;
}

int main()
{
    useClock();
    useQueryPerformanceCounter();
    useSystemClock();
    return 0;
}
