#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
#include <vector>
#include <random>
using namespace std;

#define STU8NUMBER 0x30
#define EDU8NUMBER 0x39
#define U8HYPHEN 0x2d
#define U8DOT 0x2E
#define U8BIGX 0x58

bool isIPv4(string str);

int main()
{
    string str;
    cin >> str;

    cout << str << " >> ";
    if(true==isIPv4(str)){
        cout << "IPv4です。" << endl; 
    }else{
        cout << "違います！！" << endl;
    };

    return 0;
};

bool isIPv4(string str)
{
    unsigned int x;
    unsigned int IPV4[4];
    unsigned int idx;

    idx = 0;

    for(int idx =0;idx<4;idx++) IPV4[idx]=0;

    for(int i=0;i<str.size();++i){
        x = (unsigned int)str[i];
        //数字かチェック
        if(STU8NUMBER<=x && EDU8NUMBER>=x){
            IPV4[idx]*=10;
            IPV4[idx]+=(x-STU8NUMBER);
        }else if(U8DOT==x){
            if( idx < 3 ) {
                if(IPV4[idx]>255) return false;
                idx++;
            }else{
                return false;
            };
        }else{
            return false;
        };
    };
    return true;
};