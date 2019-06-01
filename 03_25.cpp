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

#define UTFSP 0x20
#define UTF80 0x30
#define UTF89 0x39
#define UTF8A 0x41
#define UTF8Z 0x5a
#define UTF8a 0x61
#define UTF8z 0x7a

bool capitalize(string& str) {
    string tmp;
    unsigned int x;
    bool code0=true;

    for(int i=0;i<str.size();i+=1) {
        x = (unsigned int)str[i];
        if(code0){
            if(UTF8a <= x && UTF8z >= x ){
                str[i] = (char)(x - UTF8a + UTF8A);
                code0 = false;
            }
        } else {
            if(UTFSP == (unsigned int)str[i]){ code0 = true; }
        }
    }

    return true;
}



int main(){
    vector<unsigned int> ret;
    string strA = u8"i am a alien i am a legal alian";
    cout << strA << "=>" << endl;
    if(capitalize(strA)){
        cout<<strA<<endl;
    }
    return 0;
}
