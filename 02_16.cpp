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

bool outList(uint32_t st,uint32_t ed);
void printIPv4(uint32_t IPv4);
bool isIPv4(string str,uint32_t *ret);

int main()
{
    string str;
    uint32_t IPv4[2];
    uint8_t count;

    count = 0;
    std::cout << "Please input IPv4" << std::endl;
    //１個目入力
    do{
        std::cout << "ST >>" << std::endl;
        cin >> str;
        if(true == isIPv4(str,&IPv4[0])){
            break;
        }else{
            cout << "not IPv4" << endl;
            count++;
            if(count>=3) return 0;
        }
    }while(true);
    //２個目入力
    do{
        std::cout << "ED >>" << std::endl;
        cin >> str;
        if(true == isIPv4(str,&IPv4[1])){
            break;
        }else{
            cout << "not IPv4" << endl;
            count++;
            if(count>=3) return 0;
        }
    }while(true);

    if(IPv4[0]<IPv4[1]){
        outList(IPv4[0],IPv4[1]);
    }else{
        outList(IPv4[0],IPv4[1]);
    };
    return 0;
};

bool outList(uint32_t st,uint32_t ed)
{
    uint32_t tmp;
    tmp = st;

    do{
        printIPv4(tmp);
        tmp++;
    }while(tmp<ed);
    printIPv4(ed);

    return true;
};

void printIPv4(uint32_t IPv4)
{
    uint32_t tmp[4];
    tmp[0]=(IPv4&0xff000000);
    tmp[0]=tmp[0]>>24;
    tmp[1]=(IPv4&0x00ff0000);
    tmp[1]=tmp[1]>>16;
    tmp[2]=(IPv4&0x0000ff00);
    tmp[2]=tmp[2]>>8;
    tmp[3]=(IPv4&0x000000ff);

    cout << tmp[0] << "." << tmp[1] << "." << tmp[2] << "." << tmp[3] << endl;
    return;
};

bool isIPv4(string str,uint32_t *ret)
{
    uint32_t tmp;
    uint32_t num;
    uint8_t idx;
    uint8_t countnum;

    //初期化
    idx = 0;
    countnum = 0;
    tmp = 0;
    num = 0;
    *ret = 0;

    for(int i=0;i<str.size();++i){
        //1文字取得
        tmp = (unsigned int)str[i];
        //数字かチェック
        if(STU8NUMBER<=tmp && EDU8NUMBER>=tmp){
            countnum++;
            num*=10;
            num+=(tmp-STU8NUMBER);
        }else if(U8DOT==tmp){
            //区切り文字
            if( idx < 3 ) {
                //255(8bit)より大きいか？
                if(num>255) return false;
                *ret=*ret<<8;//8bit左シフト
                *ret+=num;
                num=0;
                countnum = 0;
                idx++;
            }else{
                //4Block以上ある
                return false;
            };
        }else{
            //数字でもどっとでもない
            return false;
        };
    };
    if(idx != 3) return false;
    if(countnum<=0) return false;
    *ret=*ret<<8;//8bit左シフト
    *ret+=num;
    num=0;
    countnum = 0;
    return true;
};

