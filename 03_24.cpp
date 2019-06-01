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
#define UTF89 0x39
#define UTF8A 0x41
#define UTF8F 0x46
#define UTF8a 0x61
#define UTF8f 0x66

bool hexToCout(string str,vector<unsigned int>& ret) {
    unsigned int tmp;
    unsigned int x;
    for(int i=0;i<str.size();i+=2) {
        tmp = 0;
        x = (unsigned int)str[i];

        if(UTF80<=x && UTF89>=x){
            tmp=x-UTF80;
        }else if(UTF8A<=x && UTF8F>=x){
            tmp=x-UTF8A+10;
        }else if(UTF8a<=x && UTF8f>=x){
            tmp=x-UTF8a+10;
        }else{
            cout<<"Err"<<endl;
            return false;
        }

        tmp=tmp<<4;
        x = (unsigned int)str[i+1];
        if(UTF80<=x && UTF89>=x){
            tmp+=(x-UTF80);
        }else if(UTF8A<=x && UTF8F>=x){
            tmp+=(x-UTF8A)+10;
        }else if(UTF8a<=x && UTF8f>=x){
            tmp+=(x-UTF8a)+10;
        }else{
            cout<<"Err"<<endl;
            return false;
        }
        ret.push_back(tmp);
    }


    return true;
}



int main(){
    vector<unsigned int> ret;
    string strA = u8"BAA80FF099CDEF";
    cout << strA << "=>" << endl;
    if(hexToCout(strA,ret)){
        cout<<"{";
        for(auto x:ret){
            cout << " 0x" << hex << (unsigned int)x ;
        }
        cout<<" }"<<endl;
    }


    string stra = u8"baa90ff099cdef";
    cout << stra << "=>" << endl;
    if(hexToCout(stra,ret)){
        cout<<"{";
        for(auto x:ret){
            cout << " 0x" << hex << (unsigned int)x ;
        }
        cout<<" }"<<endl;
    }

    string strnum = u8"01020304050609";
    cout << strnum << "=>" << endl;
    if(hexToCout(strnum,ret)){
        cout<<"{";
        for(auto x:ret){
            cout << " 0x" << hex << (unsigned int)x ;
        }
        cout<<" }"<<endl;
    }

    return 0;


}
