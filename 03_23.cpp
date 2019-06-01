#include <algorithm>
#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <random>
#include <cassert>

using namespace std;

#define UTF80 0x30
#define UTF8A 0x41

template<typename T>
void hexToCout(T hexs) {
    uint8_t tmp;
    for(auto x : hexs) {
        tmp = (uint8_t)x >> 4;
        cout << (char)(tmp < 10 ? (0x30+tmp) : (0x41+tmp-10));
        tmp = (uint8_t)x & 0x0f;
        cout << (char)(tmp < 10 ? (0x30+tmp) : (0x41+tmp-10));
    }
    cout << endl;
    return ;
}

int main(){

    vector<unsigned char> x{0xBA,0xAD,0xF0,0x0D};
    vector<unsigned char> y{11,2,3,4,5,6};
    hexToCout(x);
    hexToCout(y);
    return 0;
}

