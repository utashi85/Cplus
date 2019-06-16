#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main()
{
    /** 10段ループ */
    for(uint8_t i = 0; i < 10; i++) {

        /** インデント */
        for(uint8_t j = i; j < 10; j++) {
            cout << "   " ;
        }

        /** データ部 */
        uint8_t x = 1;

        for(uint8_t k = 0 ; k <= i; k++) {
            /** 公式 */
            uint8_t y = x;
            cout << ((y < 10) ? "  " : ((y < 100) ? " " : "" )) << +y << "   ";
            x = x * (i - k)/(k + 1);
        }

        cout << endl;
    }

};

